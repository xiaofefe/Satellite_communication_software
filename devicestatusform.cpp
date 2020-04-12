#include "devicestatusform.h"
#include "ui_DeviceStatusForm.h"
#include "qdebug.h"
DeviceStatusForm::DeviceStatusForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceStatusForm)
{
    ui->setupUi(this);

    initForm();     //初始化窗口样式


}

DeviceStatusForm::~DeviceStatusForm()
{
    delete ui;
}

//初始化窗口相关的内容
void DeviceStatusForm::initForm()
{
    //安装过滤器
    InstallFiller();

    //初始化设备开关标识
    for(int i = 0;i<DEV_NUM;++i)
        dev_open_flag[i] = true;
    //初始化链接开关标识
    for(int i = 0;i<DEV_NUM;++i)
        link_open_flag[i] = true;

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

//点击设备调用的函数
//index:设备编号
void DeviceStatusForm::DoPreDevThing(int index)
{

    //以下内容为暂时测试使用
     DeviceButton * devs[DEV_NUM] = {      //设备
        ui->pushButton_dev1,
        ui->pushButton_dev2,
        ui->pushButton_dev3,
        ui->pushButton_dev4,
        ui->pushButton_dev5,
        ui->pushButton_dev6
    };

    ui->label_dev_info->setText("设备"+QString::number(index+1));



}

//点击链接按钮调用的函数
//index:设备编号
void DeviceStatusForm::DoPreLinkThing(int index)
{
      ui->label_dev_info->setText("链接"+QString::number(index+1));


      //以下内容为暂时测试使用
      //变换开关
      if(link_open_flag[index])
          link_open_flag[index] = false;
      else
          link_open_flag[index] = true;

      switch(index)
      {
        case 0:
        if(link_open_flag[0] == true)
            ui->Button_link1->setStyleSheet("border-image: url(:/images/up_gre_dou_alp.png)");
        else
            ui->Button_link1->setStyleSheet("border-image: url(:/images/up_red_dou_alp.png)");
          break;
        case 1:
        if(link_open_flag[1] == true)
            ui->Button_link2->setStyleSheet("border-image: url(:/images/down_gre_dou_alp.png)");
        else
            ui->Button_link2->setStyleSheet("border-image: url(:/images/down_red_dou_alp.png)");
         break;
      case 2:
        if(link_open_flag[2] == true)
            ui->Button_link3->setStyleSheet("border-image: url(:/images/down_gre_dou_alp.png)");
        else
            ui->Button_link3->setStyleSheet("border-image: url(:/images/down_red_dou_alp.png)");
        case 3:
        if(link_open_flag[3] == true)
            ui->Button_link4->setStyleSheet("border-image: url(:/images/up_gre_dou_alp.png)");
        else
            ui->Button_link4->setStyleSheet("border-image: url(:/images/up_red_dou_alp.png)");
         break;
      case 4:
        if(link_open_flag[4] == true)
            ui->Button_link5->setStyleSheet("border-image: url(:/images/up_gre_dou_alp.png)");
        else
            ui->Button_link5->setStyleSheet("border-image: url(:/images/up_red_dou_alp.png)");
         break;
      case 5:
        if(link_open_flag[5] == true)
            ui->Button_link6->setStyleSheet("border-image: url(:/images/down_gre_dou_alp.png)");
        else
            ui->Button_link6->setStyleSheet("border-image: url(:/images/down_red_dou_alp.png)");
         break;
      case 6:
        if(link_open_flag[6] == true)
            ui->Button_link7->setStyleSheet("border-image: url(:/images/down_gre_dou_alp.png)");
        else
           ui->Button_link7->setStyleSheet("border-image: url(:/images/down_red_dou_alp.png)");
          break;
      case 7:
        if(link_open_flag[7] == true)
           ui->Button_link8->setStyleSheet("border-image: url(:/images/up_gre_dou_alp.png)");
        else
           ui->Button_link8->setStyleSheet("border-image: url(:/images/up_red_dou_alp.png)");

      }

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
            if(event->type() == QEvent::MouseButtonPress )      //相应单击事件
            {    
                DoPreDevThing(i);        //点击设备
            }

        }
    }

    //检测是否是链接按钮相关事件
    for(int i = 0;i<LINK_NUM;++i)
    {
        if(watched == obj_link[i])
        {
            if(event->type() == QEvent::MouseButtonPress )
            {
              DoPreLinkThing(i);     //点击link按钮
            }

        }
    }
  return QWidget::eventFilter(watched,event);       //返回父类要继续完成的事
}
