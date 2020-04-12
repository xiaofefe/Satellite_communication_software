#ifndef PEROPTFORM_H
#define PEROPTFORM_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QSplineSeries>

namespace Ui {
class PerOptForm;
}

QT_CHARTS_USE_NAMESPACE         //使用chart命名空间

class PerOptForm : public QWidget
{
    Q_OBJECT

public:
    explicit PerOptForm(QWidget *parent = 0);
    ~PerOptForm();

    void RunStaTest();      //开始进行状态测试
    void ProTestCur();      //生成测试曲线
    bool SaveTestCur();     //保存测试曲线
    bool GetTestCur(int index);      //获取测试曲线
    bool DrawComCur();      //绘制比较曲线

private:
    Ui::PerOptForm *ui;

    QChartView chartview;      //显示测试曲线区域
    QChart chart;
    QSplineSeries *series  ;     //数据集

    QSplineSeries *com_series1  ;   //比较数据集1
    QSplineSeries *com_series2  ;   //比较数据集2

};

#endif // PEROPTFORM_H
