#include "newstatewidget.h"
#include "ui_newstatewidget.h"
#include"database.h"
#include<QMessageBox>
Newstatewidget::Newstatewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Newstatewidget)
{
    this->setWindowTitle("新建任务状态");
    ui->setupUi(this);

    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignCenter);

    QStringList ModulationCodes={"16APSK-LDPC3","16APSK-LDPC4"};
    ui->comboBox->addItems(ModulationCodes);

    QStringList DemodulationCodes={"QPSK-LDPC3","QPSK-LDPC4"};
    ui->comboBox_2->addItems(DemodulationCodes);

    connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont(QString)));
    connect(ui->comboBox_2,SIGNAL(activated(QString)),this,SLOT(doSelectFont1(QString)));
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Newstatewidget::SendSignal);
}

Newstatewidget::~Newstatewidget()
{
    delete ui;
}

void Newstatewidget::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        modulationstyle=ui->comboBox->currentText();
    }
    if(ui->comboBox_2->currentIndex()==0)
    {
        demodulationstyle=ui->comboBox_2->currentText();
    }

    QMessageBox *mess= new QMessageBox();       ///???建议更换为静态方式获取QMessageBox mess;

    if(modulationstyle.isEmpty())
   {
       mess->setText("编码方式为空");
       mess->show();
   }else if(demodulationstyle.isEmpty())
   {
       mess->setText("解码码方式为空");
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

       //added by pan
       QStringList tmp = db.queryByTasknumberAll(Tasknumber);
       if(tmp.empty() ==false)
       {
           mess->setText("插入失败,Tasknumber重复");
           mess->show();
           return ;
       }

       bool f=db.insert(Tasknumber,sendingpointfre,modulationstyle,sendingratei,receivepointfre,demodulationstyle,receiveingratei);
       if(f==true)
       {
           db.queryAll();
           mess->setText("状态保存完毕");
           mess->show();
       }else
       {
           db.queryAll();
           //db.CloseDatabase(db);//关闭数据库
           mess->setText("保存失败");
           mess->show();
       }

   }
}
void Newstatewidget::SendSignal()
{
    emit TurntoFirstWindow();
}

void Newstatewidget::doSelectFont(QString str)
{

    modulationstyle=str;

}
void Newstatewidget::doSelectFont1(QString str)
{

    demodulationstyle=str;

}

