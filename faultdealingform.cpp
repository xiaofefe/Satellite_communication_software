#include "faultdealingform.h"
#include "ui_faultdealingform.h"

FaultDealingform::FaultDealingform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaultDealingform)
{
    ui->setupUi(this);
    series=new QSplineSeries();
    series->setName("曲线");
    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(7,4);
    series->append(10,5);
    *series<<QPoint(11,1)<<QPoint(13,3)<<QPoint(17,6)<<QPoint(18,3)<<QPoint(20,2);
    chart1=new QChart();
    chart1->legend()->hide();
    chart1->addSeries(series);
    chart1->createDefaultAxes();
    chart1->setTitle("曲线图");
    chart1->axisY()->setRange(0,10);

    series1=new QSplineSeries();
    series1->setName("曲线");
    series1->append(0,6);
    series1->append(2,4);
    series1->append(3,8);
    series1->append(7,4);
    series1->append(10,5);
    *series1<<QPoint(11,1)<<QPoint(13,3)<<QPoint(17,6)<<QPoint(18,3)<<QPoint(20,2);
    chart2=new QChart();
    chart2->legend()->hide();
    chart2->addSeries(series1);
    chart2->createDefaultAxes();
    chart2->setTitle("曲线图");
    chart2->axisY()->setRange(0,12);


    ui->graphicsView->setChart(chart1);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView_2->setChart(chart2);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);

//ui->widget->setVisible(false);

}
void FaultDealingform::sendWraningprocess()
{
    //发送警告信息
}
void FaultDealingform::receivedWraningprocess(){
    //接收警告信息
}
void FaultDealingform::savequickPictureInformation()
{
    //保存快照信息
}
FaultDealingform::~FaultDealingform()
{
    delete ui;
}
