/********************************************************************************
** Form generated from reading UI file 'traffic_light.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFIC_LIGHT_H
#define UI_TRAFFIC_LIGHT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(687, 416);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(120, 260, 181, 61));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(370, 260, 181, 61));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 70, 251, 16));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "open camera", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "switch light", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Please use the IC card to unlock", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFIC_LIGHT_H
