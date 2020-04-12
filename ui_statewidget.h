/********************************************************************************
** Form generated from reading UI file 'statewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEWIDGET_H
#define UI_STATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateWidget
{
public:
    QWidget *widget;
    QLabel *label;
    QFrame *line;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *widget_3;
    QLabel *label_5;
    QComboBox *ModulationCodingcomboBox;
    QWidget *widget_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QWidget *widget_5;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QWidget *widget_6;
    QLabel *label_10;
    QComboBox *DemodulationCodingcomboBox;
    QWidget *widget_7;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_6;
    QWidget *widget_8;
    QPushButton *SavepushButton;
    QPushButton *CancelpushButton;

    void setupUi(QWidget *StateWidget)
    {
        if (StateWidget->objectName().isEmpty())
            StateWidget->setObjectName(QStringLiteral("StateWidget"));
        StateWidget->resize(554, 511);
        StateWidget->setMinimumSize(QSize(554, 511));
        StateWidget->setMaximumSize(QSize(554, 511));
        widget = new QWidget(StateWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 10, 441, 71));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 91, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(200, 30, 41, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 101, 35));
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(240, 20, 101, 35));
        lineEdit_2->setFont(font);
        widget_2 = new QWidget(StateWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(50, 80, 441, 61));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 20, 121, 31));
        label_3->setFont(font);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 20, 61, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        lineEdit_3 = new QLineEdit(widget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 20, 104, 31));
        lineEdit_3->setFont(font);
        widget_3 = new QWidget(StateWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(50, 140, 441, 51));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 15, 111, 21));
        label_5->setFont(font);
        ModulationCodingcomboBox = new QComboBox(widget_3);
        ModulationCodingcomboBox->setObjectName(QStringLiteral("ModulationCodingcomboBox"));
        ModulationCodingcomboBox->setGeometry(QRect(120, 11, 181, 31));
        widget_4 = new QWidget(StateWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(50, 190, 441, 61));
        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 30, 101, 21));
        label_6->setFont(font);
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 30, 54, 16));
        QFont font2;
        font2.setPointSize(11);
        label_7->setFont(font2);
        lineEdit_4 = new QLineEdit(widget_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 20, 121, 31));
        lineEdit_4->setFont(font);
        widget_5 = new QWidget(StateWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(50, 250, 441, 51));
        label_8 = new QLabel(widget_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 15, 111, 31));
        label_8->setFont(font);
        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 10, 61, 41));
        label_9->setFont(font1);
        lineEdit_5 = new QLineEdit(widget_5);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 10, 121, 31));
        lineEdit_5->setFont(font);
        widget_6 = new QWidget(StateWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(50, 300, 441, 51));
        label_10 = new QLabel(widget_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 20, 111, 21));
        label_10->setFont(font);
        DemodulationCodingcomboBox = new QComboBox(widget_6);
        DemodulationCodingcomboBox->setObjectName(QStringLiteral("DemodulationCodingcomboBox"));
        DemodulationCodingcomboBox->setGeometry(QRect(120, 10, 181, 31));
        widget_7 = new QWidget(StateWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(50, 350, 441, 51));
        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 20, 101, 21));
        label_11->setFont(font);
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 20, 54, 16));
        label_12->setFont(font2);
        lineEdit_6 = new QLineEdit(widget_7);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 10, 121, 31));
        lineEdit_6->setFont(font);
        widget_8 = new QWidget(StateWidget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(50, 400, 441, 80));
        SavepushButton = new QPushButton(widget_8);
        SavepushButton->setObjectName(QStringLiteral("SavepushButton"));
        SavepushButton->setGeometry(QRect(10, 30, 101, 31));
        CancelpushButton = new QPushButton(widget_8);
        CancelpushButton->setObjectName(QStringLiteral("CancelpushButton"));
        CancelpushButton->setGeometry(QRect(280, 30, 111, 31));

        retranslateUi(StateWidget);

        QMetaObject::connectSlotsByName(StateWidget);
    } // setupUi

    void retranslateUi(QWidget *StateWidget)
    {
        StateWidget->setWindowTitle(QApplication::translate("StateWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("StateWidget", "\344\273\273\345\212\241\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("StateWidget", "\344\270\255\351\242\221\345\217\221\351\200\201\347\202\271\351\242\221", Q_NULLPTR));
        label_4->setText(QApplication::translate("StateWidget", "MHz", Q_NULLPTR));
        label_5->setText(QApplication::translate("StateWidget", "\350\260\203\345\210\266\347\274\226\347\240\201\346\226\271\345\274\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("StateWidget", "\345\217\221\351\200\201\346\225\260\346\215\256\351\200\237\347\216\207", Q_NULLPTR));
        label_7->setText(QApplication::translate("StateWidget", "kbps", Q_NULLPTR));
        label_8->setText(QApplication::translate("StateWidget", "\344\270\255\351\242\221\346\216\245\346\224\266\347\202\271\351\242\221", Q_NULLPTR));
        label_9->setText(QApplication::translate("StateWidget", "MHz", Q_NULLPTR));
        label_10->setText(QApplication::translate("StateWidget", "\350\247\243\350\260\203\347\274\226\347\240\201\346\226\271\345\274\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("StateWidget", "\346\224\266\346\225\260\346\215\256\351\200\237\347\216\207", Q_NULLPTR));
        label_12->setText(QApplication::translate("StateWidget", "kbps", Q_NULLPTR));
        SavepushButton->setText(QApplication::translate("StateWidget", "\344\277\235\345\255\230\350\256\276\347\275\256\347\212\266\346\200\201", Q_NULLPTR));
        CancelpushButton->setText(QApplication::translate("StateWidget", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StateWidget: public Ui_StateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEWIDGET_H
