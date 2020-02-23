#ifndef COREWINDOW_H
#define COREWINDOW_H

#include <QMainWindow>
#include"devicestatus.h"
#include"faultdealing.h"
#include"taskstatus.h"
#include"performanceandoptimization.h"
namespace Ui {
class CoreWindow;
}

class CoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoreWindow(QWidget *parent = nullptr);
    ~CoreWindow();
    void switchPage();
    void sendSingnalCancel();
signals:
    void CancelSignal();
private:
    Ui::CoreWindow *ui;
    Devicestatus *ds;
    FaultDealing *fd;
    Taskstatus *ts;
    Performanceandoptimization *po;
};

#endif // COREWINDOW_H
