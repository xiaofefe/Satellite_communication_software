#include "corewindow.h"
#include "ui_corewindow.h"

CoreWindow::CoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreWindow)
{
    ui->setupUi(this);
    ds=new Devicestatus(this);
    ui->stackedWidget->addWidget(ds);
    ui->stackedWidget->setCurrentWidget(ds);
    fd=new FaultDealing(this);
    ui->stackedWidget->addWidget(fd);
    ts=new Taskstatus(this);
    ui->stackedWidget->addWidget(ts);
    po=new Performanceandoptimization(this);
    ui->stackedWidget->addWidget(po);
    connect(ui->pushButtonDeviceStatus,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonFaultDealing,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonTaskStatus,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonPerandOptimiziaton,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButton,&QPushButton::clicked,this,&CoreWindow::sendSingnalCancel);
}
void CoreWindow::sendSingnalCancel()
{
    emit CancelSignal();
}
void CoreWindow::switchPage(){
 QPushButton *button = qobject_cast<QPushButton*>(sender());
 if(button==ui->pushButtonDeviceStatus)
 {
      ui->stackedWidget->setCurrentWidget(ds);
 }else if(button==ui->pushButtonFaultDealing)
 {
       ui->stackedWidget->setCurrentWidget(fd);
 }else if(button==ui->pushButtonTaskStatus)
 {
       ui->stackedWidget->setCurrentWidget(ts);
 }else
 {
        ui->stackedWidget->setCurrentWidget(po);
 }
}
CoreWindow::~CoreWindow()
{
    delete ui;
}
