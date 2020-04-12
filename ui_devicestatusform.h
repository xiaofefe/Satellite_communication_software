/********************************************************************************
** Form generated from reading UI file 'devicestatusform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESTATUSFORM_H
#define UI_DEVICESTATUSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "devicebutton.h"
#include "linkbutton.h"

QT_BEGIN_NAMESPACE

class Ui_DeviceStatusForm
{
public:
    QPushButton *testButton;
    QFrame *frame;
    DeviceButton *pushButton_dev2;
    QLabel *label_node2;
    QPushButton *Button_link8;
    DeviceButton *pushButton_dev4;
    LinkButton *Button_link3;
    LinkButton *Button_link5;
    QLabel *label_node1;
    DeviceButton *pushButton_dev1;
    DeviceButton *pushButton_dev6;
    DeviceButton *pushButton_dev3;
    DeviceButton *pushButton_dev5;
    LinkButton *Button_link6;
    LinkButton *Button_link1;
    LinkButton *Button_link2;
    LinkButton *Button_link7;
    LinkButton *Button_link4;
    QFrame *frame_2;
    QLabel *label_dev_info;

    void setupUi(QWidget *DeviceStatusForm)
    {
        if (DeviceStatusForm->objectName().isEmpty())
            DeviceStatusForm->setObjectName(QStringLiteral("DeviceStatusForm"));
        DeviceStatusForm->resize(735, 539);
        testButton = new QPushButton(DeviceStatusForm);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(320, 240, 75, 23));
        testButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/down_gre_dou.png);\n"
""));
        testButton->setFlat(true);
        frame = new QFrame(DeviceStatusForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 671, 231));
        frame->setStyleSheet(QLatin1String("border: 1px solid; border-radius: 5px;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_dev2 = new DeviceButton(frame);
        pushButton_dev2->setObjectName(QStringLiteral("pushButton_dev2"));
        pushButton_dev2->setGeometry(QRect(20, 160, 71, 31));
        pushButton_dev2->setAutoFillBackground(false);
        label_node2 = new QLabel(frame);
        label_node2->setObjectName(QStringLiteral("label_node2"));
        label_node2->setGeometry(QRect(460, 100, 35, 25));
        label_node2->setStyleSheet(QStringLiteral("border-image: url(:/images/sw_gre_alp.png);"));
        Button_link8 = new QPushButton(frame);
        Button_link8->setObjectName(QStringLiteral("Button_link8"));
        Button_link8->setGeometry(QRect(490, 120, 90, 40));
        Button_link8->setStyleSheet(QStringLiteral("border-image: url(:/images/up_gre_dou_alp.png);"));
        pushButton_dev4 = new DeviceButton(frame);
        pushButton_dev4->setObjectName(QStringLiteral("pushButton_dev4"));
        pushButton_dev4->setGeometry(QRect(300, 160, 71, 31));
        Button_link3 = new LinkButton(frame);
        Button_link3->setObjectName(QStringLiteral("Button_link3"));
        Button_link3->setGeometry(QRect(90, 120, 90, 40));
        Button_link3->setStyleSheet(QStringLiteral("border-image: url(:/images/down_gre_dou_alp.png);"));
        Button_link3->setFlat(true);
        Button_link5 = new LinkButton(frame);
        Button_link5->setObjectName(QStringLiteral("Button_link5"));
        Button_link5->setGeometry(QRect(380, 60, 90, 40));
        Button_link5->setStyleSheet(QStringLiteral("border-image: url(:/images/up_gre_dou_alp.png);"));
        label_node1 = new QLabel(frame);
        label_node1->setObjectName(QStringLiteral("label_node1"));
        label_node1->setGeometry(QRect(180, 100, 35, 25));
        label_node1->setStyleSheet(QStringLiteral("border-image: url(:/images/sw_gre_alp.png);"));
        pushButton_dev1 = new DeviceButton(frame);
        pushButton_dev1->setObjectName(QStringLiteral("pushButton_dev1"));
        pushButton_dev1->setGeometry(QRect(20, 30, 71, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_dev1->sizePolicy().hasHeightForWidth());
        pushButton_dev1->setSizePolicy(sizePolicy);
        pushButton_dev1->setAutoDefault(false);
        pushButton_dev6 = new DeviceButton(frame);
        pushButton_dev6->setObjectName(QStringLiteral("pushButton_dev6"));
        pushButton_dev6->setGeometry(QRect(580, 160, 71, 31));
        pushButton_dev3 = new DeviceButton(frame);
        pushButton_dev3->setObjectName(QStringLiteral("pushButton_dev3"));
        pushButton_dev3->setGeometry(QRect(300, 30, 71, 31));
        pushButton_dev5 = new DeviceButton(frame);
        pushButton_dev5->setObjectName(QStringLiteral("pushButton_dev5"));
        pushButton_dev5->setGeometry(QRect(580, 30, 71, 31));
        Button_link6 = new LinkButton(frame);
        Button_link6->setObjectName(QStringLiteral("Button_link6"));
        Button_link6->setGeometry(QRect(490, 60, 90, 40));
        Button_link6->setStyleSheet(QStringLiteral("border-image: url(:/images/down_gre_dou_alp.png);"));
        Button_link1 = new LinkButton(frame);
        Button_link1->setObjectName(QStringLiteral("Button_link1"));
        Button_link1->setGeometry(QRect(90, 60, 90, 40));
        Button_link1->setStyleSheet(QStringLiteral("border-image: url(:/images/up_gre_dou_alp.png);"));
        Button_link2 = new LinkButton(frame);
        Button_link2->setObjectName(QStringLiteral("Button_link2"));
        Button_link2->setGeometry(QRect(210, 60, 90, 40));
        Button_link2->setStyleSheet(QStringLiteral("border-image: url(:/images/down_gre_dou_alp.png);"));
        Button_link7 = new LinkButton(frame);
        Button_link7->setObjectName(QStringLiteral("Button_link7"));
        Button_link7->setGeometry(QRect(380, 120, 90, 40));
        Button_link7->setStyleSheet(QStringLiteral("border-image: url(:/images/down_gre_dou_alp.png);"));
        Button_link4 = new LinkButton(frame);
        Button_link4->setObjectName(QStringLiteral("Button_link4"));
        Button_link4->setGeometry(QRect(210, 120, 90, 40));
        Button_link4->setStyleSheet(QStringLiteral("border-image: url(:/images/up_gre_dou_alp.png);"));
        pushButton_dev2->raise();
        label_node2->raise();
        Button_link8->raise();
        pushButton_dev4->raise();
        Button_link3->raise();
        Button_link5->raise();
        label_node1->raise();
        pushButton_dev1->raise();
        pushButton_dev6->raise();
        pushButton_dev3->raise();
        pushButton_dev5->raise();
        Button_link6->raise();
        Button_link1->raise();
        Button_link2->raise();
        Button_link7->raise();
        Button_link4->raise();
        frame_2 = new QFrame(DeviceStatusForm);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 260, 711, 261));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_dev_info = new QLabel(frame_2);
        label_dev_info->setObjectName(QStringLiteral("label_dev_info"));
        label_dev_info->setGeometry(QRect(0, 0, 671, 251));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_dev_info->setFont(font);
        label_dev_info->setStyleSheet(QStringLiteral("border: 1px solid; border-radius: 5px;\\n"));
        label_dev_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(DeviceStatusForm);

        QMetaObject::connectSlotsByName(DeviceStatusForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceStatusForm)
    {
        DeviceStatusForm->setWindowTitle(QApplication::translate("DeviceStatusForm", "Form", Q_NULLPTR));
        testButton->setText(QString());
        pushButton_dev2->setText(QApplication::translate("DeviceStatusForm", "Dev2", Q_NULLPTR));
        label_node2->setText(QString());
        Button_link8->setText(QString());
        pushButton_dev4->setText(QApplication::translate("DeviceStatusForm", "Dev4", Q_NULLPTR));
        Button_link3->setText(QString());
        Button_link5->setText(QString());
        label_node1->setText(QString());
        pushButton_dev1->setText(QApplication::translate("DeviceStatusForm", "Dev1", Q_NULLPTR));
        pushButton_dev6->setText(QApplication::translate("DeviceStatusForm", "Dev6", Q_NULLPTR));
        pushButton_dev3->setText(QApplication::translate("DeviceStatusForm", "Dev3", Q_NULLPTR));
        pushButton_dev5->setText(QApplication::translate("DeviceStatusForm", "Dev5", Q_NULLPTR));
        Button_link6->setText(QString());
        Button_link1->setText(QString());
        Button_link2->setText(QString());
        Button_link7->setText(QString());
        Button_link4->setText(QString());
        label_dev_info->setText(QApplication::translate("DeviceStatusForm", "\350\256\276\345\244\207\347\212\266\346\200\201\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeviceStatusForm: public Ui_DeviceStatusForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESTATUSFORM_H
