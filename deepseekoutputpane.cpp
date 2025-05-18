#include "deepseekoutputpane.h"
#include "deepseektr.h"

#include <QVBoxLayout>
#include <QToolButton>
#include <QTextBlock>

namespace DeepSeek {
namespace Internal {

DeepSeekOutputPane::DeepSeekOutputPane() :
    m_outputWidget(nullptr)
{
}

DeepSeekOutputPane::~DeepSeekOutputPane()
{
    delete m_outputWidget;
}

QWidget *DeepSeekOutputPane::outputWidget(QWidget *parent)
{
    if (!m_outputWidget) {
        m_outputWidget = new QPlainTextEdit(parent);
        m_outputWidget->setReadOnly(true);
        m_outputWidget->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
        m_outputWidget->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        m_outputWidget->setUndoRedoEnabled(false);
    }
    return m_outputWidget;
}

QString DeepSeekOutputPane::displayName() const
{
    return Tr::tr("DeepSeek");
}

int DeepSeekOutputPane::priorityInStatusBar() const
{
    return 1;
}

void DeepSeekOutputPane::clearContents()
{
    if (m_outputWidget)
        m_outputWidget->clear();
}

void DeepSeekOutputPane::visibilityChanged(bool visible)
{
    Q_UNUSED(visible)
}

void DeepSeekOutputPane::setFocus()
{
    if (m_outputWidget)
        m_outputWidget->setFocus();
}

bool DeepSeekOutputPane::hasFocus() const
{
    return m_outputWidget && m_outputWidget->hasFocus();
}

bool DeepSeekOutputPane::canFocus() const
{
    return true;
}

bool DeepSeekOutputPane::canNavigate() const
{
    return false;
}

bool DeepSeekOutputPane::canNext() const
{
    return false;
}

bool DeepSeekOutputPane::canPrevious() const
{
    return false;
}

void DeepSeekOutputPane::goToNext()
{
    // Not implemented
}

void DeepSeekOutputPane::goToPrev()
{
    // Not implemented
}

void DeepSeekOutputPane::appendText(const QString &text)
{
    if (!m_outputWidget)
        return;
    
    // Append separator if needed
    if (!m_outputWidget->document()->isEmpty())
        m_outputWidget->appendPlainText("\n-----------------------------\n");
    
    m_outputWidget->appendPlainText(text);
    
    // Auto-scroll to bottom
    QTextCursor cursor = m_outputWidget->textCursor();
    cursor.movePosition(QTextCursor::End);
    m_outputWidget->setTextCursor(cursor);
}

} // namespace Internal
} // namespace DeepSeek
