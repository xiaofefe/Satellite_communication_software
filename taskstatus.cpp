#include "taskstatus.h"
#include "ui_taskstatus.h"

Taskstatus::Taskstatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Taskstatus)
{
    ui->setupUi(this);

}

Taskstatus::~Taskstatus()
{
    delete ui;
}
