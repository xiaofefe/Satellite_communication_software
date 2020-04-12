/********************************************************************************
** Form generated from reading UI file 'firstmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTMAINWINDOW_H
#define UI_FIRSTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstMainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *NewTaskStatePushButton;
    QPushButton *ModifyTaskStatePushButton;
    QPushButton *EnterManageSystemPushButton;
    QPushButton *pushButton;

    void setupUi(QMainWindow *FirstMainWindow)
    {
        if (FirstMainWindow->objectName().isEmpty())
            FirstMainWindow->setObjectName(QStringLiteral("FirstMainWindow"));
        FirstMainWindow->resize(1024, 589);
        FirstMainWindow->setMinimumSize(QSize(1024, 589));
        FirstMainWindow->setMaximumSize(QSize(1024, 589));
        FirstMainWindow->setStyleSheet(QLatin1String("*{\n"
"  background-image: url(:/images/weixin_Main.jpg);\n"
"}\n"
"QLabel{\n"
"  background:transparent;\n"
"  font:bold 18px;\n"
"}\n"
"QPushButton{\n"
"  border-radius:10px;\n"
"  font:bold 16px;\n"
"  background-color:rgba(255,255,255);\n"
"  border-style:outset;\n"
"}\n"
"QPushButton:pressed{\n"
"  background-color:rgba(100,255,100,200);\n"
"  border-style:inset;\n"
"}\n"
"QPushButton:hover{\n"
" background-color:rgba(100,255,100,100);\n"
"}\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(FirstMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 80, 161, 41));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(750, 80, 201, 41));
        NewTaskStatePushButton = new QPushButton(centralWidget);
        NewTaskStatePushButton->setObjectName(QStringLiteral("NewTaskStatePushButton"));
        NewTaskStatePushButton->setGeometry(QRect(560, 180, 181, 51));
        NewTaskStatePushButton->setStyleSheet(QStringLiteral(""));
        ModifyTaskStatePushButton = new QPushButton(centralWidget);
        ModifyTaskStatePushButton->setObjectName(QStringLiteral("ModifyTaskStatePushButton"));
        ModifyTaskStatePushButton->setGeometry(QRect(800, 180, 181, 51));
        EnterManageSystemPushButton = new QPushButton(centralWidget);
        EnterManageSystemPushButton->setObjectName(QStringLiteral("EnterManageSystemPushButton"));
        EnterManageSystemPushButton->setGeometry(QRect(670, 290, 201, 51));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(640, 380, 261, 51));
        FirstMainWindow->setCentralWidget(centralWidget);

        retranslateUi(FirstMainWindow);

        QMetaObject::connectSlotsByName(FirstMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FirstMainWindow)
    {
        FirstMainWindow->setWindowTitle(QApplication::translate("FirstMainWindow", "FirstMainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("FirstMainWindow", "\350\257\267\350\276\223\345\205\245\344\273\273\345\212\241\344\273\243\345\217\267\357\274\232", Q_NULLPTR));
        NewTaskStatePushButton->setText(QApplication::translate("FirstMainWindow", "\346\226\260\345\273\272\344\273\273\345\212\241\347\212\266\346\200\201", Q_NULLPTR));
        ModifyTaskStatePushButton->setText(QApplication::translate("FirstMainWindow", "\344\277\256\346\224\271\344\273\273\345\212\241\347\212\266\346\200\201", Q_NULLPTR));
        EnterManageSystemPushButton->setText(QApplication::translate("FirstMainWindow", "\350\277\233\345\205\245\345\201\245\345\272\267\347\256\241\347\220\206", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FirstMainWindow", "\350\276\223\345\205\245\350\256\276\345\244\207\345\217\202\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FirstMainWindow: public Ui_FirstMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTMAINWINDOW_H
