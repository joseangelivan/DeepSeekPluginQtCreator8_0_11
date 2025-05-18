#pragma once

#include <coreplugin/ioutputpane.h>

#include <QPlainTextEdit>

namespace DeepSeek {
namespace Internal {

class DeepSeekOutputPane : public Core::IOutputPane
{
    Q_OBJECT

public:
    DeepSeekOutputPane();
    ~DeepSeekOutputPane() override;

    // IOutputPane interface
    QWidget *outputWidget(QWidget *parent) override;

    // These methods aren't marked as virtual in the base class
    // so we shouldn't mark them as override
    QString displayName() const;
    int priorityInStatusBar() const;

    void clearContents() override;
    void visibilityChanged(bool visible) override;
    void setFocus() override;
    bool hasFocus() const override;
    bool canFocus() const override;
    bool canNavigate() const override;
    bool canNext() const override;
    bool canPrevious() const override;
    void goToNext() override;
    void goToPrev() override;

    void appendText(const QString &text);

private:
    QPlainTextEdit *m_outputWidget;
};

} // namespace Internal
} // namespace DeepSeek
