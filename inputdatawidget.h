#ifndef INPUTDATAWIDGET_H
#define INPUTDATAWIDGET_H

#include <QWidget>
#include "database.h"
namespace Ui {
class InputDataWidget;
}

class InputDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputDataWidget(QWidget *parent = nullptr);
    ~InputDataWidget();
    void saveSCMM630data();
    void saveintermediatefrequencyunitdata();
    void saveUTDT_4505Table();
    void saveComtechPSTdata();
    void SendSignal();
signals:
    void TurntoFirstWindow();
public slots:
     void doSelectTaskName(QString);
     void doSelectCodeing(QString);
     void doSelectOpenOrClose(QString);
     void doSelectEncoding(QString);
     void doSelectLocking(QString);
     void doSelectRFSwitch(QString);
     void doSelectradiofrequencySuppression(QString);
     void doSelectonlineState(QString);
private:
    Ui::InputDataWidget *ui;
    database *dabase;
    QString eqName;
    QString modulationEncoding;
    QString carrierTransmission;
    QString demodulationDecoding;
    QString decodingLocking;
    QString RFSwitch,radiofrequencySuppression,onlineState;
};

#endif // INPUTDATAWIDGET_H
