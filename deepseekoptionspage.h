#pragma once

#include <coreplugin/dialogs/ioptionspage.h>
#include <utils/id.h>
#include <utils/filepath.h>

#include <QPointer>

namespace DeepSeek {
namespace Internal {

class DeepSeekSettings;

namespace Ui {
class DeepSeekOptionsPage;
}

// Configuration page for the DeepSeek plugin
class DeepSeekOptionsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    explicit DeepSeekOptionsPage(DeepSeekSettings *settings, QObject *parent = nullptr);
    ~DeepSeekOptionsPage() override;

    QWidget *widget() override;
    void apply() override;
    void finish() override;

    // Methods to handle category settings
    void setCategory(const Utils::Id &category);
    void setDisplayCategory(const QString &displayCategory);
    void setCategoryIconPath(const Utils::FilePath &iconPath);

private:
    DeepSeekSettings *m_settings;
    QPointer<QWidget> m_widget;
    Ui::DeepSeekOptionsPage *ui;
    Utils::Id m_category;
    QString m_displayCategory;
    Utils::FilePath m_categoryIconPath;
};

} // namespace Internal
} // namespace DeepSeek
