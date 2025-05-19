#include "deepseekoptionspage.h"
#include "ui_deepseekoptionspage.h"
#include "deepseeksettings.h"
#include "deepseektr.h"

#include <coreplugin/icore.h>
#include <utils/icon.h> // Necesario para Utils::Icon
#include <QSettings>

namespace DeepSeek {
namespace Internal {

DeepSeekOptionsPage::DeepSeekOptionsPage(DeepSeekSettings *settings, QObject *parent)
    : Core::IOptionsPage(), // Changed from IOptionsPageProvider to IOptionsPage
      m_settings(settings),
      m_widget(nullptr),
      ui(nullptr)
{
    setId("DeepSeekSettings");
    setDisplayName(Tr::tr("DeepSeek"));

    // Set default category
    setCategory(Utils::Id("TextEditor"));
    setDisplayCategory(Tr::tr("Text Editor"));

    // Store parent for safe deletions
    setParent(parent);
}

DeepSeekOptionsPage::~DeepSeekOptionsPage()
{
    delete ui;
}

QWidget *DeepSeekOptionsPage::widget()
{
    if (!m_widget) {
        m_widget = new QWidget;
        ui = new Ui::DeepSeekOptionsPage;
        ui->setupUi(m_widget);

        ui->apiKeyEdit->setText(m_settings->apiKey());
        ui->apiUrlEdit->setText(m_settings->apiUrl());
        ui->modelEdit->setText(m_settings->model());
        ui->systemPromptEdit->setPlainText(m_settings->systemPrompt());
        ui->temperatureSpinBox->setValue(m_settings->temperature());
        ui->maxTokensSpinBox->setValue(m_settings->maxTokens());
    }
    return m_widget;
}

void DeepSeekOptionsPage::apply()
{
    if (!m_widget) // page was never shown
        return;

    m_settings->setApiKey(ui->apiKeyEdit->text());
    m_settings->setApiUrl(ui->apiUrlEdit->text());
    m_settings->setModel(ui->modelEdit->text());
    m_settings->setSystemPrompt(ui->systemPromptEdit->toPlainText());
    m_settings->setTemperature(ui->temperatureSpinBox->value());
    m_settings->setMaxTokens(ui->maxTokensSpinBox->value());

    // Use the global QSettings instance provided by Qt Creator
    m_settings->saveSettings(Core::ICore::settings());
}

void DeepSeekOptionsPage::finish()
{
    delete m_widget;
    m_widget = nullptr;
    delete ui;
    ui = nullptr;
}

// Implementation of category setting methods - simplified to directly set fields
void DeepSeekOptionsPage::setCategory(const Utils::Id &category)
{
    m_category = category;
}

void DeepSeekOptionsPage::setDisplayCategory(const QString &displayCategory)
{
    m_displayCategory = displayCategory;
}

void DeepSeekOptionsPage::setCategoryIconPath(const Utils::FilePath &iconPath)
{
    m_categoryIconPath = iconPath;
}

} // namespace Internal
} // namespace DeepSeek
