#include "corewindowform.h"
#include "ui_corewindowform.h"
//corewindowform
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
    listItem.append("主界面|");

    listItem.append("设备状态||0|");

    listItem.append("故障处理||0|");
    listItem.append("发送告警处理流程|故障处理||");
    listItem.append("接受告警处理流程|故障处理||");
    listItem.append("查询历史故障快照|故障处理||");


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
    int row = index.row();
    QString text = index.data().toString();
    if (text == "设备状态") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (text == "故障处理") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (text == "地图编辑") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (text == "位置调整") {
        ui->stackedWidget->setCurrentIndex(3);
    }

}
