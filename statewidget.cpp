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
       ui->lineEdit->setAlignment(Qt::AlignCenter);
        ui->lineEdit_2->setAlignment(Qt::AlignCenter);
       QStringList ModulationCodes={"16APSK-LDPC3","16APSK-LDPC4"};
        ui->ModulationCodingcomboBox->addItems(ModulationCodes);
        QStringList DemodulationCodes={"QPSK-LDPC3","QPSK-LDPC4"};
        ui->DemodulationCodingcomboBox->addItems(DemodulationCodes);
        if(!globalTasknumber.isEmpty())
       {
           QStringList list=globalTasknumber.split("-");
           ui->lineEdit->setText(list[0]);
           ui->lineEdit_2->setText(list[1]);
           database db=database();
            QStringList TaskInformation=db.queryByTasknumberAll(globalTasknumber);
            qDebug()<<TaskInformation[0]+"ccccc";
           if(TaskInformation[0]=="查找失败")
            {
                  QMessageBox *mess= new QMessageBox();
                  mess->setText("数据没有或者查找失败");
                 mess->show();
           }else
            {
                ui->lineEdit_3->setText(TaskInformation[1]);
                ui->lineEdit_4->setText(TaskInformation[3]);
                ui->lineEdit_5->setText(TaskInformation[4]);
                ui->lineEdit_6->setText(TaskInformation[6]);
            }
        }
        connect(ui->ModulationCodingcomboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont(QString)));
        connect(ui->DemodulationCodingcomboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont1(QString)));
        connect(ui->SavepushButton,&QPushButton::clicked,this,&StateWidget::SaveState);
        connect(ui->CancelpushButton,&QPushButton::clicked,this,&StateWidget::SendSignal);
    }
    void StateWidget::SaveState(){
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
        }else if (demodulationstyle.isEmpty()) {
            mess->setText("解码方式为空");
            mess->show();
       }
        else{
            QString Task1=ui->lineEdit->text();
            //qDebug()<<"Task1"<<Task1;
            QString Task2=ui->lineEdit_2->text();
           //qDebug()<<"Task2"<<Task2;
            Tasknumber=Task1+"-"+Task2;
            //qDebug()<<"Tasknumber"<<Tasknumber;
            sendingpointfre=ui->lineEdit_3->text();
            sendingrate=ui->lineEdit_4->text();
            receivepointfre=ui->lineEdit_5->text();
            receiveingrate=ui->lineEdit_6->text();
            database db=database();
            //db.createConnection();
            //float sendingpointfref=sendingpointfre.toFloat();
           int sendingratei=sendingrate.toInt();
            //float receivepointfref=receivepointfre.toFloat();
            int receiveingratei=receiveingrate.toInt();
            bool f=db.UpdataDatabase(Tasknumber,sendingpointfre,modulationstyle,sendingratei,receivepointfre,demodulationstyle,receiveingratei);
           if(f==true)
           {
              db.queryAll();
               mess->setText("状态保存成功");
               mess->show();
            }else
            {
                //db.queryAll();
                //db.CloseDatabase(db);//关闭数据库
                mess->setText("保存失败");
                mess->show();
            }

        }

}
void StateWidget::SendSignal()
{
    emit TurntoFirstWindow();
}
StateWidget::~StateWidget()
{
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
