#include "deepseekplugin.h"
#include "deepseekwidget.h"
#include "deepseekoptionspage.h"
#include "deepseeksettings.h"
#include "deepseekoutputpane.h"
#include "deepseektr.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>

#include <texteditor/texteditor.h>
#include <texteditor/textdocument.h>

#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

using namespace Core;

namespace DeepSeek {
namespace Internal {

DeepSeekPlugin::DeepSeekPlugin()
{
    // Create your members
    m_networkManager = new QNetworkAccessManager(this);
}

DeepSeekPlugin::~DeepSeekPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool DeepSeekPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, you should add your actions to the plugins menu

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    m_settings = new DeepSeekSettings(this);
    m_settings->readSettings(Core::ICore::settings());

    // Create options page
    auto optionsPage = new DeepSeekOptionsPage(m_settings, this);
    // Use the compatible version of addAutoReleasedObject
    ExtensionSystem::PluginManager::addObject(optionsPage);

    // Create output pane
    m_outputPane = new DeepSeekOutputPane();
    // Use the compatible version for output pane too
    ExtensionSystem::PluginManager::addObject(m_outputPane);

    initializeMenus();

    return true;
}

void DeepSeekPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, you can use any
    // objects from other plugins and the core.
}

ExtensionSystem::IPlugin::ShutdownFlag DeepSeekPlugin::aboutToShutdown()
{
    // Save settings
    if (m_settings)
        m_settings->saveSettings(Core::ICore::settings());

    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void DeepSeekPlugin::initializeMenus()
{
    // Create DeepSeek menu
    ActionContainer *menu = ActionManager::createMenu("DeepSeek.Menu");
    menu->menu()->setTitle(Tr::tr("DeepSeek"));
    ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    // Create Actions
    auto actionId = "DeepSeek.Action";
    QAction *action = new QAction(Tr::tr("Ask DeepSeek"), this);
    Core::Command *cmd = ActionManager::registerAction(action, actionId);
    menu->addAction(cmd);

    connect(action, &QAction::triggered, this, &DeepSeekPlugin::triggerDeepSeekAction);
}

void DeepSeekPlugin::triggerDeepSeekAction()
{
    IEditor *editor = EditorManager::currentEditor();
    if (!editor) {
        QMessageBox::warning(Core::ICore::dialogParent(),
                             Tr::tr("DeepSeek"),
                             Tr::tr("No active editor."));
        return;
    }

    TextEditor::TextEditorWidget *editorWidget = qobject_cast<TextEditor::TextEditorWidget *>(editor->widget());
    if (!editorWidget) {
        QMessageBox::warning(Core::ICore::dialogParent(),
                             Tr::tr("DeepSeek"),
                             Tr::tr("Current editor is not a text editor."));
        return;
    }

    QString selectedText = editorWidget->textCursor().selectedText();
    if (selectedText.isEmpty()) {
        QMessageBox::warning(Core::ICore::dialogParent(),
                             Tr::tr("DeepSeek"),
                             Tr::tr("No text selected."));
        return;
    }

    DeepSeekWidget *widget = new DeepSeekWidget(m_settings);
    widget->setPrompt(selectedText);
    widget->exec();

    if (widget->result() == QDialog::Accepted) {
        QString response = widget->getResponse();
        if (!response.isEmpty()) {
            m_outputPane->appendText(response);
            m_outputPane->popup(Core::IOutputPane::ModeSwitch);
        }
    }

    delete widget;
}

void DeepSeekPlugin::sendApiRequest(const QString &endpoint, const QByteArray &data)
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_settings->apiUrl() + endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QString apiKey = m_settings->apiKey();
    if (!apiKey.isEmpty()) {
        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
    }

    QNetworkReply *reply = m_networkManager->post(request, data);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();

        if(reply->error() != QNetworkReply::NoError) {
            m_outputPane->appendText(Tr::tr("Error: %1").arg(reply->errorString()));
            m_outputPane->popup(Core::IOutputPane::ModeSwitch);
            return;
        }

        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData);

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            if (obj.contains("content")) {
                QString content = obj["content"].toString();
                m_outputPane->appendText(content);
                m_outputPane->popup(Core::IOutputPane::ModeSwitch);
            }
        }
    });
}

} // namespace Internal
} // namespace DeepSeek
