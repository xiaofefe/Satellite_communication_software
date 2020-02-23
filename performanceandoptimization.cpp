#include "performanceandoptimization.h"
#include "ui_performanceandoptimization.h"

Performanceandoptimization::Performanceandoptimization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Performanceandoptimization)
{
    ui->setupUi(this);
}

Performanceandoptimization::~Performanceandoptimization()
{
    delete ui;
}
