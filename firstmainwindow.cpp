#include "firstmainwindow.h"
#include "ui_firstmainwindow.h"
#include <QDebug>
QString globalTasknumber;
FirstMainWindow::FirstMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstMainWindow)
{
    ui->setupUi(this);
    //查询数据库
    //this->setAttribute(Qt::WA_DeleteOnClose, true);
    dabase=new database();//创建数据库对象
    dabase->createConnection();//连接数据库
    //dabase->deleteTableTasknumber();
    dabase->createTable();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
    //设置comboBox的下拉个数
    ui->comboBox->setMaxVisibleItems(6);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectFont(QString)));
    //修改任务状态
    connect(ui->ModifyTaskStatePushButton,&QPushButton::pressed,this,&FirstMainWindow::TurnToSTateModiflyTaskWidget);
    //新建任务状态
    connect(ui->NewTaskStatePushButton,&QPushButton::pressed,this,&FirstMainWindow::TurnToSTateNewTaskWidget);
    //进入主界面
    connect(ui->EnterManageSystemPushButton,&QPushButton::clicked,this,&FirstMainWindow::TurnToManageSystem);
    //回到第一个选择界面
    connect(&coreWindow,&CoreWindow::CancelSignal,this,&FirstMainWindow::DoSomethingAboutCoreMian);

}
void FirstMainWindow::doSelectFont(QString _str)
{
     Daihao=_str;
}
void FirstMainWindow::DoSomethingAboutCoreMian()
{
    this->show();
    coreWindow.hide();
}
void FirstMainWindow::TurnToManageSystem(){
    this->hide();
    coreWindow.show();
}
void FirstMainWindow::TurnToSTateModiflyTaskWidget()
{
    if(ui->comboBox->currentIndex()==0)
    {
      globalTasknumber=ui->comboBox->currentText();
    }else
    {
      globalTasknumber=Daihao;
    }
    this->close();
    stateWi=new StateWidget();
    //接受子窗口的信号
    connect(stateWi,&StateWidget::TurntoFirstWindow,this,&FirstMainWindow::DoSomethingAboutModiflySignal);
    stateWi->show();
}
void FirstMainWindow::DoSomethingAboutModiflySignal()
{
    stateWi->close();
    this->show();
    ui->comboBox->clear();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
}
void FirstMainWindow::DoSomethingAboutNewSignal()
{
    newStateWi->close();
    this->show();
    ui->comboBox->clear();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
}
void FirstMainWindow::TurnToSTateNewTaskWidget(){
    this->hide();
    newStateWi=new Newstatewidget();
    connect(newStateWi,&Newstatewidget::TurntoFirstWindow,this,&FirstMainWindow::DoSomethingAboutNewSignal);
    newStateWi->show();
}
FirstMainWindow::~FirstMainWindow()
{
    delete ui;
}
