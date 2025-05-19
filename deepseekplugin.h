#pragma once

#include <extensionsystem/iplugin.h>
#include <QObject>
#include <QNetworkAccessManager>
#include <extensionsystem/pluginmanager.h>

namespace DeepSeek {
namespace Internal {

class DeepSeekOutputPane;
class DeepSeekSettings;

class DeepSeekPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "DeepSeekPlugin.json")

public:
    DeepSeekPlugin();
    ~DeepSeekPlugin() override;

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void initializeMenus();
    void triggerDeepSeekAction();
    void sendApiRequest(const QString &endpoint, const QByteArray &data);

private:
    DeepSeekOutputPane *m_outputPane = nullptr;
    DeepSeekSettings *m_settings = nullptr;
    QNetworkAccessManager *m_networkManager = nullptr;
};

} // namespace Internal
} // namespace DeepSeek
