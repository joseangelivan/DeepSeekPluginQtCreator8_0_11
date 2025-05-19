#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>

// Forward declaration to avoid including QtcSettings header
namespace Utils {
class QtcSettings;
}

namespace DeepSeek {
namespace Internal {

class DeepSeekSettings : public QObject
{
    Q_OBJECT

public:
    explicit DeepSeekSettings(QObject *parent = nullptr);

    void readSettings(Utils::QtcSettings *settings);
    void saveSettings(Utils::QtcSettings *settings) const;

    QString apiKey() const;
    void setApiKey(const QString &apiKey);

    QString apiUrl() const;
    void setApiUrl(const QString &apiUrl);

    QString model() const;
    void setModel(const QString &model);

    QString systemPrompt() const;
    void setSystemPrompt(const QString &systemPrompt);

    double temperature() const;
    void setTemperature(double temperature);

    int maxTokens() const;
    void setMaxTokens(int maxTokens);

signals:
    void apiKeyChanged(const QString &apiKey);
    void apiUrlChanged(const QString &apiUrl);
    void modelChanged(const QString &model);
    void systemPromptChanged(const QString &systemPrompt);
    void temperatureChanged(double temperature);
    void maxTokensChanged(int maxTokens);

private:
    QString m_apiKey;
    QString m_apiUrl;
    QString m_model;
    QString m_systemPrompt;
    double m_temperature;
    int m_maxTokens;
};

} // namespace Internal
} // namespace DeepSeek
