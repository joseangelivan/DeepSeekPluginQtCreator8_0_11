#include "deepseeksettings.h"

namespace DeepSeek {
namespace Internal {

DeepSeekSettings::DeepSeekSettings(QObject *parent)
    : QObject(parent),
      m_apiUrl("https://api.deepseek.com"),
      m_model("deepseek-coder"),
      m_systemPrompt("You are a helpful code assistant."),
      m_temperature(0.7),
      m_maxTokens(2048)
{
}

void DeepSeekSettings::readSettings(QSettings *settings)
{
    settings->beginGroup(QLatin1String("DeepSeekPlugin"));
    m_apiKey = settings->value(QLatin1String("ApiKey"), QString()).toString();
    m_apiUrl = settings->value(QLatin1String("ApiUrl"), m_apiUrl).toString();
    m_model = settings->value(QLatin1String("Model"), m_model).toString();
    m_systemPrompt = settings->value(QLatin1String("SystemPrompt"), m_systemPrompt).toString();
    m_temperature = settings->value(QLatin1String("Temperature"), m_temperature).toDouble();
    m_maxTokens = settings->value(QLatin1String("MaxTokens"), m_maxTokens).toInt();
    settings->endGroup();
}

void DeepSeekSettings::saveSettings(QSettings *settings) const
{
    settings->beginGroup(QLatin1String("DeepSeekPlugin"));
    settings->setValue(QLatin1String("ApiKey"), m_apiKey);
    settings->setValue(QLatin1String("ApiUrl"), m_apiUrl);
    settings->setValue(QLatin1String("Model"), m_model);
    settings->setValue(QLatin1String("SystemPrompt"), m_systemPrompt);
    settings->setValue(QLatin1String("Temperature"), m_temperature);
    settings->setValue(QLatin1String("MaxTokens"), m_maxTokens);
    settings->endGroup();
}

QString DeepSeekSettings::apiKey() const
{
    return m_apiKey;
}

void DeepSeekSettings::setApiKey(const QString &apiKey)
{
    if (m_apiKey != apiKey) {
        m_apiKey = apiKey;
        emit apiKeyChanged(apiKey);
    }
}

QString DeepSeekSettings::apiUrl() const
{
    return m_apiUrl;
}

void DeepSeekSettings::setApiUrl(const QString &apiUrl)
{
    if (m_apiUrl != apiUrl) {
        m_apiUrl = apiUrl;
        emit apiUrlChanged(apiUrl);
    }
}

QString DeepSeekSettings::model() const
{
    return m_model;
}

void DeepSeekSettings::setModel(const QString &model)
{
    if (m_model != model) {
        m_model = model;
        emit modelChanged(model);
    }
}

QString DeepSeekSettings::systemPrompt() const
{
    return m_systemPrompt;
}

void DeepSeekSettings::setSystemPrompt(const QString &systemPrompt)
{
    if (m_systemPrompt != systemPrompt) {
        m_systemPrompt = systemPrompt;
        emit systemPromptChanged(systemPrompt);
    }
}

double DeepSeekSettings::temperature() const
{
    return m_temperature;
}

void DeepSeekSettings::setTemperature(double temperature)
{
    if (m_temperature != temperature) {
        m_temperature = temperature;
        emit temperatureChanged(temperature);
    }
}

int DeepSeekSettings::maxTokens() const
{
    return m_maxTokens;
}

void DeepSeekSettings::setMaxTokens(int maxTokens)
{
    if (m_maxTokens != maxTokens) {
        m_maxTokens = maxTokens;
        emit maxTokensChanged(maxTokens);
    }
}

} // namespace Internal
} // namespace DeepSeek
