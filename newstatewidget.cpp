#include "newstatewidget.h"
#include "ui_newstatewidget.h"
#include"database.h"
#include<QMessageBox>
Newstatewidget::Newstatewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Newstatewidget)
{
    //this->setWindowTitle("新建任务状态");
    ui->setupUi(this);
    //设置任务代号字体样式
    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignCenter);
    //编码和解码选择数据设置
    QStringList ModulationCodes={"16APSK-LDPC3","16APSK-LDPC4"};
    ui->comboBox->addItems(ModulationCodes);

    QStringList DemodulationCodes={"QPSK-LDPC3","QPSK-LDPC4"};
    ui->comboBox_2->addItems(DemodulationCodes);
    //选择编码方式连接函数
    connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(doSelectFont(QString)));
    connect(ui->comboBox_2,SIGNAL(activated(QString)),this,SLOT(doSelectFont1(QString)));
    //想主界面发射信号
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Newstatewidget::SendSignal);
}

Newstatewidget::~Newstatewidget()
{
    delete ui;
}
//ui视图中设置了信号和嘈函数，所以看不到具体连接函数
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

     QMessageBox *mess= new QMessageBox();       //已更换

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
       QString Task2=ui->lineEdit_2->text();
       Tasknumber=Task1+"-"+Task2;

       sendingpointfre=ui->lineEdit_3->text();
       sendingrate=ui->lineEdit_4->text();
       receivepointfre=ui->lineEdit_5->text();
       receiveingrate=ui->lineEdit_6->text();
       //数据插入
       database db=database();
       //数据格式转换
       int sendingratei=sendingrate.toInt();
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
void Newstatewidget::clearNewStateData(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

