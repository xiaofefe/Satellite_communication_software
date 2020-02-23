#include "devicestatus.h"
#include "ui_devicestatus.h"

Devicestatus::Devicestatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Devicestatus)
{
    ui->setupUi(this);
    ui->textEditParmShow->setText("设备参数显示");
    ui->textEdit_2->setText("设备连接关系图");
}

Devicestatus::~Devicestatus()
{
    delete ui;
}
