#include "statewidget.h"
#include "ui_statewidget.h"
#include <QMessageBox>
#include <QCursor>
#include <QDebug>
#include"database.h"

extern QString globalTasknumber;

StateWidget::StateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateWidget)
{
    ui->setupUi(this);


    connect(ui->ModulationCodingcomboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont(QString)));
    connect(ui->DemodulationCodingcomboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont1(QString)));
    connect(ui->SavepushButton,&QPushButton::clicked,this,&StateWidget::SaveState);
    connect(ui->CancelpushButton,&QPushButton::clicked,this,&StateWidget::SendSignal);
}

//保存状态
void StateWidget::SaveState()
{
    //判断选择框选取什么数据，并保存
    if(ui->ModulationCodingcomboBox->currentIndex()==0)
    {
       modulationstyle=ui->ModulationCodingcomboBox->currentText();
    }
   if(ui->DemodulationCodingcomboBox->currentIndex()==0)
    {
        demodulationstyle=ui->DemodulationCodingcomboBox->currentText();
    }
     QMessageBox *mess= new QMessageBox();

    if(modulationstyle.isEmpty())
    {
        mess->setText("编码方式为空");
        mess->show();
    }
    else if (demodulationstyle.isEmpty()) {
        mess->setText("解码方式为空");
        mess->show();
   }
    else{
        QString Task1=ui->lineEdit->text();
        QString Task2=ui->lineEdit_2->text();
        Tasknumber=Task1+"-"+Task2;//任务代号

        sendingpointfre=ui->lineEdit_3->text();
        sendingrate=ui->lineEdit_4->text();
        receivepointfre=ui->lineEdit_5->text();
        receiveingrate=ui->lineEdit_6->text();
        //数据库数据更新
        database db=database();
        //数据类型转换
        int sendingratei=sendingrate.toInt();
        int receiveingratei=receiveingrate.toInt();
        //判断数据是否更新数据成功
        bool f=db.UpdataDatabase(Tasknumber,sendingpointfre,modulationstyle,sendingratei,receivepointfre,demodulationstyle,receiveingratei);

        if(f==true)
       {
           mess->setText("状态保存成功");
           mess->show();
        }else
        {
            mess->setText("保存失败");
            mess->show();
        }

    }

}
//发送信号
void StateWidget::SendSignal()
{
    emit TurntoFirstWindow();
}
StateWidget::~StateWidget()
{
    //qDebug()<<"statewidge in destory:"<<this;
    delete ui;
}
void StateWidget::doSelectFont(QString str)
{
   modulationstyle=str;
}
void StateWidget::doSelectFont1(QString str)
{
   demodulationstyle=str;
}
//stateWidget数据刷新处理
void StateWidget::FillData()
{
    //任务代号字体居中设置
    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignCenter);
   //解码和编码选择框数据设置
    QStringList ModulationCodes={"16APSK-LDPC3","16APSK-LDPC4"};
    ui->ModulationCodingcomboBox->addItems(ModulationCodes);
    QStringList DemodulationCodes={"QPSK-LDPC3","QPSK-LDPC4"};
    ui->DemodulationCodingcomboBox->addItems(DemodulationCodes);
    //设置界面数据并显示
    if(!globalTasknumber.isEmpty())
   {
       QStringList list=globalTasknumber.split("-");
       ui->lineEdit->setText(list[0]);
       ui->lineEdit_2->setText(list[1]);

       database db=database();//数据库对象
       QStringList TaskInformation=db.queryByTasknumberAll(globalTasknumber);
       qDebug()<<TaskInformation[0];//测试输出数据库数据

        if(TaskInformation[0]=="查找失败")
        {
          QMessageBox *mess= new QMessageBox();
          mess->setText("数据没有或者查找失败");
          mess->show();
       }
        else
        {
            ui->lineEdit_3->setText(TaskInformation[1]);
            ui->lineEdit_4->setText(TaskInformation[3]);
            ui->lineEdit_5->setText(TaskInformation[4]);
            ui->lineEdit_6->setText(TaskInformation[6]);
        }
    }

}
