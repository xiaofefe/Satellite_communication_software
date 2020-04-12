#include "corewindowform.h"
#include "ui_corewindowform.h"
#include <QtDebug>
#include"taskstatepage.h"
#include"global.h"
#include"faultdealingform.h"
corewindowform::corewindowform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::corewindowform)
{
    ui->setupUi(this);
    this->setWindowTitle("健康管理界面");
    InitCoreForm();
}

corewindowform::~corewindowform()
{
    delete ui;
}

//初始化核心窗口导航栏
void corewindowform::InitCoreForm()
{
    //导航栏样式设置
    ui->navListView->setIcoColorBg(false);
    ui->navListView->setLineColor(QColor(32, 53, 74));
    ui->navListView->setBgNormalColor(QColor(52, 73, 94));
    ui->navListView->setBgSelectedColor(QColor(24, 189, 155));
    ui->navListView->setBgHoverColor(QColor(24, 189, 155));
    ui->navListView->setTextNormalColor(QColor(250, 250, 250));
    ui->navListView->setTextSelectedColor(QColor(230, 230, 230));
    ui->navListView->setTextHoverColor(QColor(10, 10, 10));

    //设置数据方式
    QStringList listItem;
    //listItem.append("主界面||0|");

    listItem.append("设备状态||0|");

    listItem.append("故障处理||0|");
//    listItem.append("发送告警处理流程|故障处理||");
//    listItem.append("接受告警处理流程|故障处理||");
//    listItem.append("查询历史故障快照|故障处理||");
      listItem.append("发送告警处理流程|故障处理|0|");
      listItem.append("接受告警处理流程|故障处理|0|");
      listItem.append("查询历史故障快照|故障处理|0|");


    listItem.append("任务状态||0|");
    listItem.append("选择任务代号|任务状态|0|");
    listItem.append("保存任务快照|任务状态|0|");

    listItem.append("性能与优化||0|");
    listItem.append("进行设备状态测试|性能与优化|0|");
    listItem.append("生成测试曲线|性能与优化|0|");
    listItem.append("保存测试曲线|性能与优化|0|");
    listItem.append("比较显示曲线1|性能与优化|0|");
    listItem.append("比较显示曲线2|性能与优化|0|");
    listItem.append("绘制比较显示曲线|性能与优化|0|");

    listItem.append("帮助文档||1|");

    ui->navListView->setData(listItem);

    ui->navListView->setCurrentIndex(ui->navListView->indexAt(QPoint(0, 0)));

    connect(ui->CancelpushButton,&QPushButton::clicked,this,&corewindowform::SendCancel);

}
//返回主机面
void corewindowform::SendCancel()
{
    emit CancelSignal();
}
//导航栏点击函数
void corewindowform::on_navListView_pressed(const QModelIndex &index)
{
    //int row = index.row();
    QString text = index.data().toString();
    if (text == "设备状态") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (text == "故障处理") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (text == "任务状态") {
        ui->taskstatepage->RefreshData(globalmessage::globalTasknumber);
        ui->stackedWidget->setCurrentIndex(2);
    } else if (text == "性能与优化") {
        qDebug()<<"test bug";
        ui->stackedWidget->setCurrentIndex(3);
        qDebug()<<"test1 bug";
    }
    //任务状态
    if(text=="选择任务代号")
    {
        ui->taskstatepage->SelectTaskNumber();
    }else if(text=="保存任务快照")
    {
        ui->taskstatepage->SaveTaskQuickPhoto();
    }
  //故障处理
    if(text=="发送告警处理流程")
    {
        ui->FaultDealingPage->sendWraningprocess();
    }else if(text=="接受告警处理流程")
    {
        ui->FaultDealingPage->receivedWraningprocess();
    }else if(text=="查询历史故障快照")
    {
       ui->FaultDealingPage->savequickPictureInformation();
    }
    //性能优化页面的各个按钮
    if(text == "进行设备状态测试")
    {
        ui->PerOptPage->RunStaTest();       //进行设备状态测试
    }
    else if(text == "生成测试曲线")
    {
        ui->PerOptPage->ProTestCur();       //产生测试曲线
    }
    else if("保存测试曲线" == text)
    {
        ui->PerOptPage->SaveTestCur();      //保存测试曲线
    }
    else if("比较显示曲线1" == text)
    {
        ui->PerOptPage->GetTestCur(1);       //获取测试曲线
    }
    else if("比较显示曲线2" == text)
    {
        ui->PerOptPage->GetTestCur(2);       //获取测试曲线
    }
    else if("绘制比较显示曲线" == text)
    {
        ui->PerOptPage->DrawComCur();       //绘出两条比较曲线
    }

   // qDebug()<<text;

}
