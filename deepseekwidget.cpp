#include "deepseekwidget.h"
#include "ui_deepseekwidget.h"
#include "deepseeksettings.h"
#include "deepseektr.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

namespace DeepSeek {
namespace Internal {

DeepSeekWidget::DeepSeekWidget(DeepSeekSettings *settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeepSeekWidget),
    m_settings(settings)
{
    ui->setupUi(this);

    connect(ui->sendButton, &QPushButton::clicked, this, &DeepSeekWidget::onSendClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

DeepSeekWidget::~DeepSeekWidget()
{
    delete ui;
}

void DeepSeekWidget::setPrompt(const QString &prompt)
{
    ui->promptEdit->setPlainText(prompt);
}

QString DeepSeekWidget::getResponse() const
{
    return m_response;
}

void DeepSeekWidget::onSendClicked()
{
    QString prompt = ui->promptEdit->toPlainText();
    if (prompt.isEmpty()) {
        QMessageBox::warning(this, Tr::tr("DeepSeek"), Tr::tr("Please enter a prompt."));
        return;
    }

    if (m_settings->apiKey().isEmpty()) {
        QMessageBox::warning(this, Tr::tr("DeepSeek"), 
                            Tr::tr("API Key is not set. Please configure it in Tools > Options > DeepSeek."));
        return;
    }

    ui->sendButton->setEnabled(false);
    ui->responseEdit->clear();
    ui->responseEdit->setPlainText(Tr::tr("Requesting..."));

    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    
    QNetworkRequest request;
    request.setUrl(QUrl(m_settings->apiUrl() + "/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(m_settings->apiKey()).toUtf8());

    QJsonObject jsonObject;
    jsonObject["model"] = m_settings->model();
    
    QJsonArray messages;
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = m_settings->systemPrompt();
    messages.append(systemMessage);

    QJsonObject userMessage;
    userMessage["role"] = "user";
    userMessage["content"] = prompt;
    messages.append(userMessage);

    jsonObject["messages"] = messages;
    jsonObject["temperature"] = m_settings->temperature();
    jsonObject["max_tokens"] = m_settings->maxTokens();

    QJsonDocument doc(jsonObject);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = networkManager->post(request, data);

    connect(reply, &QNetworkReply::finished, this, [this, reply, networkManager]() {
        reply->deleteLater();
        networkManager->deleteLater(); 
        
        ui->sendButton->setEnabled(true);
        
        if (reply->error() != QNetworkReply::NoError) {
            ui->responseEdit->setPlainText(Tr::tr("Error: %1").arg(reply->errorString()));
            return;
        }
        
        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        
        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            if (obj.contains("choices") && obj["choices"].isArray()) {
                QJsonArray choices = obj["choices"].toArray();
                if (!choices.isEmpty() && choices[0].isObject()) {
                    QJsonObject choice = choices[0].toObject();
                    if (choice.contains("message") && choice["message"].isObject()) {
                        QJsonObject message = choice["message"].toObject();
                        if (message.contains("content")) {
                            m_response = message["content"].toString();
                            ui->responseEdit->setPlainText(m_response);
                            accept();
                            return;
                        }
                    }
                }
            }
        }
        
        ui->responseEdit->setPlainText(Tr::tr("Failed to parse response."));
    });
}

} // namespace Internal
} // namespace DeepSeek
