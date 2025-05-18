#pragma once

#include <src/plugins/coreplugin/dialogs/ioptionspage.h>

#include <QPointer>

namespace DeepSeek {
namespace Internal {

class DeepSeekSettings;

namespace Ui {
class DeepSeekOptionsPage;
}

class DeepSeekOptionsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    explicit DeepSeekOptionsPage(DeepSeekSettings *settings, QObject *parent = nullptr);
    ~DeepSeekOptionsPage() override;

    QWidget *widget() override;
    void apply() override;
    void finish() override;

private:
    DeepSeekSettings *m_settings;
    QPointer<QWidget> m_widget;
    Ui::DeepSeekOptionsPage *ui;
};

} // namespace Internal
} // namespace DeepSeek
