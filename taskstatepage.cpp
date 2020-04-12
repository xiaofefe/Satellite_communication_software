#include "taskstatepage.h"
#include "ui_taskstatepage.h"
#include <QDebug>
#include"popselecttasknumber.h"
TaskStatePage::TaskStatePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskStatePage)
{
    ui->setupUi(this);
}
void TaskStatePage::RefreshData(QString s){
    //判断是否选择任务代号
    qDebug()<<s;
    dabase=new database();
    dabase->createConnection();
    QStringList datas=dabase->queryByTasknumberAll(s);
    //从数据库读取任务代号相关参数
    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setColumnCount(6);
    QStringList HorizonLabels={"中频发送点频","调制解码","发数据速率","中频接收点频","解调编码","收数据速率"};
    QStringList datatimes={"2020/4/1/22:09","2020/4/1/22:09","2020/4/1/22:09","2020/4/1/22:09","2020/4/1/22:10","2020/4/1/22:10","2020/4/1/22:10"};
    ui->tableWidget->setHorizontalHeaderLabels(HorizonLabels);
    ui->tableWidget->setVerticalHeaderLabels(datatimes);
    QString TaskNameLabel=datas.value(0);
    ui->label_2->setText(TaskNameLabel);
    for(int i=0;i<7;i++)
    {
      for(int j=0;j<6;j++)
      {
          ui->tableWidget->setItem(i,j,new QTableWidgetItem(datas.value(j+1)));
      }
    }

}
void TaskStatePage::SelectTaskNumber(){
    PopSelectTaskNumber *p=new PopSelectTaskNumber();
    p->show();
}
void TaskStatePage::SaveTaskQuickPhoto(){
    qDebug()<<"保存任务快照";
}
TaskStatePage::~TaskStatePage()
{
    delete ui;
}
