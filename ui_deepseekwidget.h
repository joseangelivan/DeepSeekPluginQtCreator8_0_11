/********************************************************************************
** Form generated from reading UI file 'deepseekwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPSEEKWIDGET_H
#define UI_DEEPSEEKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

namespace DeepSeek {
namespace Internal {

class Ui_DeepSeekWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *promptLabel;
    QPlainTextEdit *promptEdit;
    QLabel *responseLabel;
    QPlainTextEdit *responseEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DeepSeek__Internal__DeepSeekWidget)
    {
        if (DeepSeek__Internal__DeepSeekWidget->objectName().isEmpty())
            DeepSeek__Internal__DeepSeekWidget->setObjectName("DeepSeek__Internal__DeepSeekWidget");
        DeepSeek__Internal__DeepSeekWidget->resize(600, 500);
        verticalLayout = new QVBoxLayout(DeepSeek__Internal__DeepSeekWidget);
        verticalLayout->setObjectName("verticalLayout");
        promptLabel = new QLabel(DeepSeek__Internal__DeepSeekWidget);
        promptLabel->setObjectName("promptLabel");

        verticalLayout->addWidget(promptLabel);

        promptEdit = new QPlainTextEdit(DeepSeek__Internal__DeepSeekWidget);
        promptEdit->setObjectName("promptEdit");
        promptEdit->setMinimumSize(QSize(0, 100));

        verticalLayout->addWidget(promptEdit);

        responseLabel = new QLabel(DeepSeek__Internal__DeepSeekWidget);
        responseLabel->setObjectName("responseLabel");

        verticalLayout->addWidget(responseLabel);

        responseEdit = new QPlainTextEdit(DeepSeek__Internal__DeepSeekWidget);
        responseEdit->setObjectName("responseEdit");
        responseEdit->setReadOnly(true);

        verticalLayout->addWidget(responseEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendButton = new QPushButton(DeepSeek__Internal__DeepSeekWidget);
        sendButton->setObjectName("sendButton");

        horizontalLayout->addWidget(sendButton);

        cancelButton = new QPushButton(DeepSeek__Internal__DeepSeekWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DeepSeek__Internal__DeepSeekWidget);

        QMetaObject::connectSlotsByName(DeepSeek__Internal__DeepSeekWidget);
    } // setupUi

    void retranslateUi(QDialog *DeepSeek__Internal__DeepSeekWidget)
    {
        DeepSeek__Internal__DeepSeekWidget->setWindowTitle(QCoreApplication::translate("DeepSeek::Internal::DeepSeekWidget", "DeepSeek", nullptr));
        promptLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekWidget", "Prompt:", nullptr));
        responseLabel->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekWidget", "Response:", nullptr));
        sendButton->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekWidget", "Send", nullptr));
        cancelButton->setText(QCoreApplication::translate("DeepSeek::Internal::DeepSeekWidget", "Cancel", nullptr));
    } // retranslateUi

};

} // namespace Internal
} // namespace DeepSeek

namespace DeepSeek {
namespace Internal {
namespace Ui {
    class DeepSeekWidget: public Ui_DeepSeekWidget {};
} // namespace Ui
} // namespace Internal
} // namespace DeepSeek

#endif // UI_DEEPSEEKWIDGET_H
