
#ifndef DeviceStatusForm_H
#define DeviceStatusForm_H

#include <QWidget>
#include <QModelIndex>

#define DEV_NUM 6           //设备数量
#define LINK_NUM 8          //链接数量


namespace Ui
{
class DeviceStatusForm;
}

class DeviceStatusForm : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceStatusForm(QWidget *parent = 0);
    ~DeviceStatusForm();

    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::DeviceStatusForm *ui;

    bool dev_open_flag[DEV_NUM];        //设备开关标识
    bool link_open_flag[LINK_NUM];      //链接开关标识

    void InstallFiller();       //给各个控件安装过滤器

    void DoPreDevThing(int index);       //点击设备

    void DoPreLinkThing(int index);      //点击链接


private slots:
    void initForm();


};

#endif // DeviceStatusForm_H
