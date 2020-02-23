#include "faultdealing.h"
#include "ui_faultdealing.h"

FaultDealing::FaultDealing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaultDealing)
{
    ui->setupUi(this);
}

FaultDealing::~FaultDealing()
{
    delete ui;
}
