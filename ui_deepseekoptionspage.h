/********************************************************************************
** Form generated from reading UI file 'deepseekoptionspage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPSEEKOPTIONSPAGE_H
#define UI_DEEPSEEKOPTIONSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace DeepSeek {
namespace Internal {

class Ui_DeepSeekOptionsPage
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *apiKeyLabel;
    QLineEdit *apiKeyEdit;
    QLabel *apiUrlLabel;
    QLineEdit *apiUrlEdit;
    QLabel *modelLabel;
    QLineEdit *modelEdit;
    QLabel *systemPromptLabel;
    QPlainTextEdit *systemPromptEdit;
    QLabel *temperatureLabel;
    QDoubleSpinBox *temperatureSpinBox;
    QLabel *maxTokensLabel;
    QSpinBox *maxTokensSpinBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DeepSeek__Internal__DeepSeekOptionsPage)
    {
        if (DeepSeek__Internal__DeepSeekOptionsPage->objectName().isEmpty())
            DeepSeek__Internal__DeepSeekOptionsPage->setObjectName("DeepSeek__Internal__DeepSeekOptionsPage");
        DeepSeek__Internal__DeepSeekOptionsPage->resize(500, 500);
        verticalLayout = new QVBoxLayout(DeepSeek__Internal__DeepSeekOptionsPage);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        apiKeyLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        apiKeyLabel->setObjectName("apiKeyLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, apiKeyLabel);

        apiKeyEdit = new QLineEdit(DeepSeek__Internal__DeepSeekOptionsPage);
        apiKeyEdit->setObjectName("apiKeyEdit");
        apiKeyEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, apiKeyEdit);

        apiUrlLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        apiUrlLabel->setObjectName("apiUrlLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, apiUrlLabel);

        apiUrlEdit = new QLineEdit(DeepSeek__Internal__DeepSeekOptionsPage);
        apiUrlEdit->setObjectName("apiUrlEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, apiUrlEdit);

        modelLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        modelLabel->setObjectName("modelLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, modelLabel);

        modelEdit = new QLineEdit(DeepSeek__Internal__DeepSeekOptionsPage);
        modelEdit->setObjectName("modelEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, modelEdit);

        systemPromptLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        systemPromptLabel->setObjectName("systemPromptLabel");
        systemPromptLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        formLayout->setWidget(3, QFormLayout::LabelRole, systemPromptLabel);

        systemPromptEdit = new QPlainTextEdit(DeepSeek__Internal__DeepSeekOptionsPage);
        systemPromptEdit->setObjectName("systemPromptEdit");
        systemPromptEdit->setMinimumSize(QSize(0, 100));

        formLayout->setWidget(3, QFormLayout::FieldRole, systemPromptEdit);

        temperatureLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        temperatureLabel->setObjectName("temperatureLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, temperatureLabel);

        temperatureSpinBox = new QDoubleSpinBox(DeepSeek__Internal__DeepSeekOptionsPage);
        temperatureSpinBox->setObjectName("temperatureSpinBox");
        temperatureSpinBox->setMinimum(0.010000000000000);
        temperatureSpinBox->setMaximum(2.000000000000000);
        temperatureSpinBox->setSingleStep(0.100000000000000);
        temperatureSpinBox->setValue(0.700000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, temperatureSpinBox);

        maxTokensLabel = new QLabel(DeepSeek__Internal__DeepSeekOptionsPage);
        maxTokensLabel->setObjectName("maxTokensLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, maxTokensLabel);

        maxTokensSpinBox = new QSpinBox(DeepSeek__Internal__DeepSeekOptionsPage);
        maxTokensSpinBox->setObjectName("maxTokensSpinBox");
        maxTokensSpinBox->setMinimum(16);
        maxTokensSpinBox->setMaximum(16384);
        maxTokensSpinBox->setValue(2048);

        formLayout->setWidget(5, QFormLayout::FieldRole, maxTokensSpinBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DeepSeek__Internal__DeepSeekOptionsPage);

        QMetaObject::connectSlotsByName(DeepSeek__Internal__DeepSeekOptionsPage);
    } // setupUi

    void retranslateUi(QWidget *DeepSeek__Internal__DeepSeekOptionsPage)
    {
        apiKeyLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "API Key:", nullptr));
        apiUrlLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "API URL:", nullptr));
        modelLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "Model:", nullptr));
        systemPromptLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "System Prompt:", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "Temperature:", nullptr));
        maxTokensLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekOptionsPage", "Max Tokens:", nullptr));
        (void)DeepSeek__Internal__DeepSeekOptionsPage;
    } // retranslateUi

};

} // namespace Internal
} // namespace DeepSeek

namespace DeepSeek {
namespace Internal {
namespace Ui {
    class DeepSeekOptionsPage: public Ui_DeepSeekOptionsPage {};
} // namespace Ui
} // namespace Internal
} // namespace DeepSeek

#endif // UI_DEEPSEEKOPTIONSPAGE_H
