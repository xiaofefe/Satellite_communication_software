#ifndef COREMAINWINDOW_H
#define COREMAINWINDOW_H

#include <QMainWindow>
#include"devicestatus.h"
#include"faultdealing.h"
#include"taskstatus.h"
#include"performanceandoptimization.h"
namespace Ui {
class CoreMainWindow;
}

class CoreMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoreMainWindow(QWidget *parent = nullptr);
    ~CoreMainWindow();

private slots:
    void on_pushButton_Devicestatus_clicked();

    void on_pushButton_5_clicked();

    void on_pushButtonDeviceStatus_clicked();

    void on_pushButtonFaultHanding_clicked();

    void on_pushButtonTaskStatus_clicked();

    void on_pushButtonPerforAndOptimization_clicked();

private:
    Ui::CoreMainWindow *ui;
    Devicestatus *ds;
    FaultDealing *fd;
    Taskstatus *ts;
    Performanceandoptimization *po;
};

#endif // COREMAINWINDOW_H
