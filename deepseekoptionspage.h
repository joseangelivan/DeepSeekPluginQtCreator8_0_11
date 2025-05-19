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

// Página de configuración del plugin DeepSeek
class DeepSeekOptionsPage : public Core::IOptionsPageProvider
{
    Q_OBJECT

public:
    explicit DeepSeekOptionsPage(DeepSeekSettings *settings, QObject *parent = nullptr);
    ~DeepSeekOptionsPage() override;

    QWidget *widget();
    void apply();
    void finish();

    // IOptionsPageProvider methods
    void setCategory(Utils::Id category);
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
