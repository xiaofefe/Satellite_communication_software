#include "firstmainwindow.h"
#include "ui_firstmainwindow.h"
#include <QDebug>
#include"global.h"
#include<QMessageBox>
#include<QFile>
#include"taskstatepage.h"
FirstMainWindow::FirstMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstMainWindow)
{
     ui->setupUi(this);
     stateWi=new StateWidget();
     connect(stateWi,&StateWidget::TurntoFirstWindow,this,&FirstMainWindow::DoSomethingAboutModiflySignal);
     stateWi->close();

     newStateWi=new Newstatewidget();
     connect(newStateWi,&Newstatewidget::TurntoFirstWindow,this,&FirstMainWindow::DoSomethingAboutNewSignal);

     coreWindow=new corewindowform();
     //回到第一个选择界面
     connect(coreWindow,&corewindowform::CancelSignal,this,&FirstMainWindow::DoSomethingAboutCoreMian);

    //查询数据库
    dabase=new database();//创建数据库对象
    QSqlDatabase db=dabase->createConnection();//创建数据库
    //dabase->deleteTableTasknumber();//删除数据库表
    QSqlQuery query(db);
    if(db.tables().contains("TaskDaiHaoTable"))//判断表是否存在
    {
         qDebug()<<"数据表已经创建"<<endl;
    }else
    {
         dabase->createTable();///不需要每一次都创建数据表，第一次就ok
    }
    inputdatawidget=new InputDataWidget();
    //回到主界面
    connect(inputdatawidget,&InputDataWidget::TurntoFirstWindow,this,&FirstMainWindow::DoSomethingAboutdataDeal);
    tasknumber=dabase->queryTasknumbersAll();
    //qDebug()<<tasknumber;
    ui->comboBox->addItems(tasknumber);
    //设置comboBox的下拉个数
    ui->comboBox->setMaxVisibleItems(6);
    //更换下拉菜单选择项
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectFont(QString)));
    //修改任务状态
    connect(ui->ModifyTaskStatePushButton,&QPushButton::pressed,this,&FirstMainWindow::TurnToSTateModiflyTaskWidget);
    //新建任务状态
    connect(ui->NewTaskStatePushButton,&QPushButton::pressed,this,&FirstMainWindow::TurnToSTateNewTaskWidget);
    //进入主界面
    connect(ui->EnterManageSystemPushButton,&QPushButton::clicked,this,&FirstMainWindow::TurnToManageSystem);
    //输入设备参数
    connect(ui->pushButton,&QPushButton::pressed,this,&FirstMainWindow::TurnToInputDataWidget);

}
//跳转输入数据界面
void FirstMainWindow::TurnToInputDataWidget()
{
    this->hide();
    inputdatawidget->show();
}
//任务代号下拉选择确定
void FirstMainWindow::doSelectFont(QString _str)
{
     Daihao=_str;
}
void FirstMainWindow::DoSomethingAboutCoreMian()
{
    coreWindow->close();
    if(coreWindow != NULL)
    {
        //delete stateWi;
        qDebug()<<"new coreWindow:"<<coreWindow;
    }
    else
    {
        qDebug()<<"coreWindow is null:"<<coreWindow;
    }
    this->show();
    //更新主界面数据
    ui->comboBox->clear();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
}
void FirstMainWindow::DoSomethingAboutdataDeal()
{
    inputdatawidget->hide();
    this->show();
}
//转到管理页面
void FirstMainWindow::TurnToManageSystem(){
    if(ui->comboBox->currentIndex()==0)
    {
      globalmessage::globalTasknumber=ui->comboBox->currentText();
    }
    else
    {
      globalmessage::globalTasknumber=Daihao;
    }
    //modified by pan
    if(globalmessage::globalTasknumber.isEmpty())      //当任务代号不为空时，才能跳转到修改页面
    {
       QMessageBox *mess= new QMessageBox(this);    //暂时以firstmainwindow作为其父页面
       mess->setText("任务代号为空！");
       mess->show();
    }
    else
    {
        this->hide();
        coreWindow->show();
    }
}

//转到修改页面
void FirstMainWindow::TurnToSTateModiflyTaskWidget()
{
    if(ui->comboBox->currentIndex()==0)
    {
      globalmessage::globalTasknumber=ui->comboBox->currentText();
    }
    else
    {
      globalmessage::globalTasknumber=Daihao;
    }
    //modified by pan
    if(globalmessage::globalTasknumber.isEmpty())      //当任务代号不为空时，才能跳转到修改页面
    {
       QMessageBox *mess= new QMessageBox(this);    //暂时以firstmainwindow作为其父页面
       mess->setText("任务代号为空！");
       mess->show();
    }
    else
    {
        this->hide();
        stateWi->FillData();
        stateWi->show();
    }
}
 //返回跳转主界面
void FirstMainWindow::DoSomethingAboutModiflySignal()
{
    stateWi->close();
    if(stateWi != NULL)
    {
        //delete stateWi;
        qDebug()<<"new stateWi:"<<stateWi;
    }
    else
    {
        qDebug()<<"stateWi is null:"<<stateWi;
    }
    this->show();
    //更新主界面数据
    ui->comboBox->clear();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
}
//跳转新建任务状态界面
void FirstMainWindow::TurnToSTateNewTaskWidget(){
    this->hide();
    newStateWi->clearNewStateData();
    newStateWi->show();
}
void FirstMainWindow::DoSomethingAboutNewSignal()
{
    newStateWi->close();
    //delete newStateWi;
    this->show();
    //更新主界面数据
    ui->comboBox->clear();
    tasknumber=dabase->queryTasknumbersAll();
    ui->comboBox->addItems(tasknumber);
}
FirstMainWindow::~FirstMainWindow()
{
    delete ui;
}
