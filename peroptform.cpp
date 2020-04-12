#include "peroptform.h"
#include "ui_peroptform.h"

#include <QGridLayout>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

PerOptForm::PerOptForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PerOptForm)
{
    ui->setupUi(this);


    QGridLayout *gridlayout = new QGridLayout;

    //添加第一行测试输出
    gridlayout->addWidget(ui->widget_test1,0,0,1,1);
    gridlayout->addWidget(ui->arr_label1,0,1,1,1);
    gridlayout->addWidget(ui->widget_test2,0,2,1,1);
    gridlayout->addWidget(ui->arr_label2,0,3,1,1);
    gridlayout->addWidget(ui->widget_test3,0,4,1,1);
    gridlayout->addWidget(ui->arr_label3,0,5,1,1);

    //添加第二行测试输出
    gridlayout->addWidget(ui->widget_test4,1,0,1,1);
    gridlayout->addWidget(ui->arr_label4,1,1,1,1);
    gridlayout->addWidget(ui->widget_test5,1,2,1,1);
    gridlayout->addWidget(ui->arr_label5,1,3,1,1);
    gridlayout->addWidget(ui->widget_test6,1,4,1,1);
    gridlayout->addWidget(ui->arr_label6,1,5,1,1);

    ui->widget_test->setLayout(gridlayout);


    series   = new QSplineSeries;
    com_series1 = new QSplineSeries;    //比较数据集1
    com_series2 = new QSplineSeries;    //比较数据流2

    //测试数据1
    *series<<QPointF(1, 5) <<
             QPointF(3.5, 18) << QPointF(4.8, 7.5) << QPointF(10, 2.5);

    chart.legend()->hide();
    chart.addSeries(series);
    chart.createDefaultAxes();
    chart.setTitle("Test chart");

   //
    //设置边框
    chartview.setStyleSheet("border: 1px solid; border-radius: 5px;\n");
    chartview.setChart(&chart);


    //垂直布局放置 测试流程和测试曲线输出
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ui->widget_test);
    layout->addWidget(&chartview);
    layout->setStretch(0,1);
    layout->setStretch(1,1);
    layout->setSpacing(50);

    this->setLayout(layout);        //整个顶层页面设置垂直布局

}

PerOptForm::~PerOptForm()
{
    delete ui;
}

//运行设备状态测试
void PerOptForm::RunStaTest()
{
    qDebug()<<"测试....";
}

//产生测试曲线
void PerOptForm::ProTestCur()
{
    qDebug()<<"产生设备测试曲线....";

    series->clear();        //清除旧的数据集

    //for test
    for(int i = 0;i<4;++i)
    {
        int a = qrand()% 10;
        int b = qrand()%10;

        *series<<QPointF(a, b);

    }

    if(chart.series().size() >= 2)
    {
        //移走原来的两个比较数据集
        chart.removeSeries(com_series1);
        chart.removeSeries(com_series2);

        //加入产生的数据集
        chart.addSeries(series);
    }



}

//保存测试曲线（拟打算用文件系统实现）
bool PerOptForm::SaveTestCur()
{
    qDebug()<<"保存测试曲线....";


   QVector<QPointF> points = series->pointsVector();       //获取所有的点

   QDateTime dateTime(QDateTime::currentDateTime());
   QString file_name =  dateTime.toString("yyyy_MM_dd_HH_MM_ss")+".txt";
   QFile file(file_name);

   if(!file.open(QIODevice::WriteOnly))
   {
       QMessageBox::warning(NULL,"failed","打开文件失败");
       return false;
   }

   QDataStream out(&file);

   //遍历输出点数据
   for(int i = 0;i<points.size();++i)
   {
       QPointF t = points[i];
       out<<t.x()<<t.y();        //输出数据
     //  qDebug()<<t.x()<<" "<<t.y();
   }

    file.close();

    QMessageBox::information(NULL, "ok", "保存测试曲线成功");

    return true;
}

//获取测试曲线
bool PerOptForm::GetTestCur(int index)
{
    qDebug()<<"获取测试曲线....";
    QSplineSeries *com_series = NULL;

    if(1 == index)
        com_series = com_series1;
    else
        com_series = com_series2;

    com_series->clear();            //清空数据集

    QString file_name = QFileDialog::getOpenFileName(this,tr("获取测试曲线")
                                          ,".",tr("文本文件(*txt)"));

    QFile file(file_name);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(NULL,"failed","打开文件失败");
        return false;
    }
    QDataStream in(&file);

    float a,b;

    //遍历从指定文件中读出数据
    while(!in.atEnd())
    {
        in>>a>>b;           //从文件中读取数据

        *com_series<<QPointF(a,b);      //向数据集中输出数据

        //qDebug()<<a<<" "<<b;

    }

    file.close();
    QMessageBox::information(NULL, "ok", "获取测试曲线成功");
    return true;

}

//绘制比较曲线
bool PerOptForm::DrawComCur()
{
    if(com_series1->count() == 0)
    {
        QMessageBox::warning(NULL,"failed","比较曲线1为空");
        return false;
    }

    if(com_series2->count() == 0)
    {
        QMessageBox::warning(NULL,"failed","比较曲线2为空");
        return false;
    }

    //去除主数据集
    chart.removeSeries(series);

    //添加比较数据集显示
    chart.addSeries(com_series1);
    chart.addSeries(com_series2);

    return true;
}
