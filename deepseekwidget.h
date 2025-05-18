#pragma once

#include <QWidget>
#include <QDialog>

namespace DeepSeek {
namespace Internal {

class DeepSeekSettings;

namespace Ui {
class DeepSeekWidget;
}

class DeepSeekWidget : public QDialog
{
    Q_OBJECT

public:
    explicit DeepSeekWidget(DeepSeekSettings *settings, QWidget *parent = nullptr);
    ~DeepSeekWidget();

    void setPrompt(const QString &prompt);
    QString getResponse() const;

private slots:
    void onSendClicked();

private:
    Ui::DeepSeekWidget *ui;
    DeepSeekSettings *m_settings;
    QString m_response;
};

} // namespace Internal
} // namespace DeepSeek
