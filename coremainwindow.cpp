#include "coremainwindow.h"
#include "ui_coremainwindow.h"

CoreMainWindow::CoreMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreMainWindow)
{
    ui->setupUi(this);
    ds=new Devicestatus(this);
    ui->stackedWidget->addWidget(ds);
    fd=new FaultDealing(this);
    ui->stackedWidget->addWidget(fd);
    ts=new Taskstatus(this);
    ui->stackedWidget->addWidget(ts);
    po=new Performanceandoptimization(this);
    ui->stackedWidget->addWidget(po);
    ui->stackedWidget->setCurrentWidget(ds);

}

CoreMainWindow::~CoreMainWindow()
{
    delete ui;
}
void CoreMainWindow::on_pushButtonDeviceStatus_clicked()
{
     ui->stackedWidget->setCurrentWidget(ds);
}

void CoreMainWindow::on_pushButtonFaultHanding_clicked()
{
     ui->stackedWidget->setCurrentWidget(fd);
}

void CoreMainWindow::on_pushButtonTaskStatus_clicked()
{
     ui->stackedWidget->setCurrentWidget(ts);
}

void CoreMainWindow::on_pushButtonPerforAndOptimization_clicked()
{
     ui->stackedWidget->setCurrentWidget(po);
}
