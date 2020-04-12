/********************************************************************************
** Form generated from reading UI file 'corewindowform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COREWINDOWFORM_H
#define UI_COREWINDOWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <peroptform.h>
#include "devicestatusform.h"
#include "navlistview.h"
#include "taskstatepage.h"
#include"faultdealingform.h"
QT_BEGIN_NAMESPACE

class Ui_corewindowform
{
public:
    NavListView *navListView;
    QStackedWidget *stackedWidget;
    DeviceStatusForm *DeviceStatusPage;
    FaultDealingform *FaultDealingPage;
    TaskStatePage *taskstatepage;
    PerOptForm *PerOptPage;
    QPushButton *CancelpushButton;

    void setupUi(QWidget *corewindowform)
    {
        if (corewindowform->objectName().isEmpty())
            corewindowform->setObjectName(QStringLiteral("corewindowform"));
        corewindowform->resize(1320, 661);
        navListView = new NavListView(corewindowform);
        navListView->setObjectName(QStringLiteral("navListView"));
        navListView->setGeometry(QRect(0, 10, 201, 611));
        stackedWidget = new QStackedWidget(corewindowform);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(250, 30, 1021, 541));
        DeviceStatusPage = new DeviceStatusForm();
        DeviceStatusPage->setObjectName(QStringLiteral("DeviceStatusPage"));
        stackedWidget->addWidget(DeviceStatusPage);
        FaultDealingPage = new FaultDealingform();
        FaultDealingPage->setObjectName(QStringLiteral("FaultDealingPage"));
        stackedWidget->addWidget(FaultDealingPage);
        taskstatepage = new TaskStatePage();
        taskstatepage->setObjectName(QStringLiteral("taskstatepage"));
        stackedWidget->addWidget(taskstatepage);
        PerOptPage = new PerOptForm();
        PerOptPage->setObjectName(QStringLiteral("PerOptPage"));
        stackedWidget->addWidget(PerOptPage);
        CancelpushButton = new QPushButton(corewindowform);
        CancelpushButton->setObjectName(QStringLiteral("CancelpushButton"));
        CancelpushButton->setGeometry(QRect(992, 597, 131, 41));

        retranslateUi(corewindowform);

        QMetaObject::connectSlotsByName(corewindowform);
    } // setupUi

    void retranslateUi(QWidget *corewindowform)
    {
        corewindowform->setWindowTitle(QApplication::translate("corewindowform", "Form", Q_NULLPTR));
        CancelpushButton->setText(QApplication::translate("corewindowform", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class corewindowform: public Ui_corewindowform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COREWINDOWFORM_H
