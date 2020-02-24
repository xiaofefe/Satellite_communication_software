#include "corewindow.h"
#include "ui_corewindow.h"

CoreWindow::CoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreWindow)
{
    ui->setupUi(this);

    ds=new Devicestatus(this);      //设备状态页面
    ui->stackedWidget->addWidget(ds);
    ui->stackedWidget->setCurrentWidget(ds);

    fd=new FaultDealing(this);      //故障处理页面
    ui->stackedWidget->addWidget(fd);

    ts=new Taskstatus(this);        //任务状态页面
    ui->stackedWidget->addWidget(ts);

    po=new Performanceandoptimization(this);    //性能与优化页面
    ui->stackedWidget->addWidget(po);

    connect(ui->pushButtonDeviceStatus,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonFaultDealing,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonTaskStatus,&QPushButton::clicked,this,&CoreWindow::switchPage);
    connect(ui->pushButtonPerandOptimiziaton,&QPushButton::clicked,this,&CoreWindow::switchPage);

    connect(ui->pushButton,&QPushButton::clicked,this,&CoreWindow::sendSingnalCancel);
}

//释放取消信号，回到初始页面
void CoreWindow::sendSingnalCancel()
{
    emit CancelSignal();
}

//切换页面
void CoreWindow::switchPage()
{
     QPushButton *button = qobject_cast<QPushButton*>(sender());
     if(button==ui->pushButtonDeviceStatus)
     {
         ui->stackedWidget->setCurrentWidget(ds);
     }
     else if(button==ui->pushButtonFaultDealing)
     {
          ui->stackedWidget->setCurrentWidget(fd);
     }
     else if(button==ui->pushButtonTaskStatus)
     {
          ui->stackedWidget->setCurrentWidget(ts);
     }
     else
     {
          ui->stackedWidget->setCurrentWidget(po);
     }

}
CoreWindow::~CoreWindow()
{
    delete ui;
}
