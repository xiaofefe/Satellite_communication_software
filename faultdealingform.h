#ifndef FAULTDEALINGFORM_H
#define FAULTDEALINGFORM_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QSplineSeries>
namespace Ui {
class FaultDealingform;
}
QT_CHARTS_USE_NAMESPACE         //使用chart命名空间
class FaultDealingform : public QWidget
{
    Q_OBJECT

public:
    explicit FaultDealingform(QWidget *parent = nullptr);
    ~FaultDealingform();
    void sendWraningprocess();
    void receivedWraningprocess();
    void savequickPictureInformation();

private:
    Ui::FaultDealingform *ui;
    //QChartView *chartview;

    QChart *chart1;
    QChart *chart2;

    QSplineSeries *series;//数据集
    QSplineSeries *series1;//数据集2

};

#endif // FAULTDEALINGFORM_H
