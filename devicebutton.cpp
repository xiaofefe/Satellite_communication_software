#include "devicebutton.h"

#include<QEvent>

DeviceButton::DeviceButton(QWidget *parent):
    QPushButton(parent)
{
    setText("自定义deviceButton");
}

DeviceButton::~DeviceButton()
{

}



QString DeviceButton::ShowDevInfo()
{
    QString dev_info = "设备状态信息";        //just for test

    return dev_info;
}
