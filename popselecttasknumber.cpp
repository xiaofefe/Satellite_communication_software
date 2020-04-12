#include "popselecttasknumber.h"
#include "ui_popselecttasknumber.h"
#include "database.h"
#include"global.h"
QString tmp;
PopSelectTaskNumber::PopSelectTaskNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopSelectTaskNumber)
{
    ui->setupUi(this);
    InitWidgetData();
}
void PopSelectTaskNumber::InitWidgetData(){
    database *d=new database();
    d->createConnection();
    QStringList datas=d->queryTasknumbersAll();
    ui->comboBox->addItems(datas);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectNumber(QString)));
    connect(ui->pushButton_2,&QPushButton::pressed,this,&PopSelectTaskNumber::CancelWidget);
    connect(ui->OKpushButton,&QPushButton::pressed,this,&PopSelectTaskNumber::GetNumber);
}
void PopSelectTaskNumber::GetNumber()
{
    if(ui->comboBox->currentIndex()==0)
    {
        STaskNumber=ui->comboBox->currentText();
    }else
    {
        STaskNumber=tmp;
    }
        this->close();
}
void PopSelectTaskNumber::doSelectNumber(QString s)
{
        tmp=s;
}
void PopSelectTaskNumber::CancelWidget()
{
       this->close();
}
PopSelectTaskNumber::~PopSelectTaskNumber()
{
       delete ui;
}
