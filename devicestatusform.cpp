#pragma execution_character_set("utf-8")

#include "devicestatusform.h"
#include "ui_DeviceStatusForm.h"
#include "qdebug.h"


#define DEV_NUM 6           //设备数量
#define LINK_NUM 8          //链接数量

DeviceStatusForm::DeviceStatusForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceStatusForm)
{
    ui->setupUi(this);
    this->initForm();
}

DeviceStatusForm::~DeviceStatusForm()
{
    delete ui;
}

void DeviceStatusForm::initForm()
{

    //加载xml文件形式
    //ui->listView->readData(":/image/config.xml");

    //安装过滤器
    InstallFiller();

}


//安装事件过滤器
void DeviceStatusForm::InstallFiller()
{
    //安装设备按钮过滤器
    ui->pushButton_dev1->installEventFilter(this);
    ui->pushButton_dev2->installEventFilter(this);
    ui->pushButton_dev3->installEventFilter(this);
    ui->pushButton_dev4->installEventFilter(this);
    ui->pushButton_dev5->installEventFilter(this);
    ui->pushButton_dev6->installEventFilter(this);

    //安装链接按钮过滤器
    ui->Button_link1->installEventFilter(this);
    ui->Button_link2->installEventFilter(this);
    ui->Button_link3->installEventFilter(this);
    ui->Button_link4->installEventFilter(this);
    ui->Button_link5->installEventFilter(this);
    ui->Button_link6->installEventFilter(this);
    ui->Button_link7->installEventFilter(this);
    ui->Button_link8->installEventFilter(this);

}



//事件过滤
bool DeviceStatusForm::eventFilter(QObject *watched, QEvent *event)
{
    QObject * obj_dev[DEV_NUM] = {      //设备
        ui->pushButton_dev1,
        ui->pushButton_dev2,
        ui->pushButton_dev3,
        ui->pushButton_dev4,
        ui->pushButton_dev5,
        ui->pushButton_dev6
    };

    QObject *obj_link[LINK_NUM] = {     //链接
        ui->Button_link1,
         ui->Button_link2,
         ui->Button_link3,
         ui->Button_link4,
         ui->Button_link5,
         ui->Button_link6,
         ui->Button_link7,
         ui->Button_link8,


    };

    //检测是否是设备按钮相关事件
    for(int i = 0;i<DEV_NUM;++i)
    {
        if(watched == obj_dev[i])
        {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::Enter)
            {
                QString show_info = "设备"+QString::number(i+1)+"信息如下";
                ui->label_dev_info->setText(show_info);
            }
            else if(event->type() == QEvent::Leave)
            {
                ui->label_dev_info->setText("");
            }
        }
    }

    //检测是否是链接按钮相关事件
    for(int i = 0;i<LINK_NUM;++i)
    {
        if(watched == obj_link[i])
        {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::Enter)
            {
                QString show_info = "链接"+QString::number(i+1)+"信息如下";
                ui->label_dev_info->setText(show_info);
            }
            else if(event->type() == QEvent::Leave)
            {
                ui->label_dev_info->setText("");
            }
        }
    }




}
