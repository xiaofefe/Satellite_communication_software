#ifndef FIRSTMAINWINDOW_H
#define FIRSTMAINWINDOW_H

#include <QMainWindow>
#include "statewidget.h"
#include "database.h"
#include "newstatewidget.h"
#include "corewindowform.h"
#include "inputdatawidget.h"
#include "taskstatepage.h"
namespace Ui {
class FirstMainWindow;
}

class FirstMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstMainWindow(QWidget *parent = nullptr);
    ~FirstMainWindow();

    void TurnToSTateNewTaskWidget();
    void TurnToManageSystem();
    void TurnToInputDataWidget();


    void DoSomethingAboutModiflySignal();
    void DoSomethingAboutNewSignal();
    void DoSomethingAboutCoreMian();
    void DoSomethingAboutdataDeal();
    void TurnToSTateModiflyTaskWidget();
public slots:
     void doSelectFont(QString);
private:
    Ui::FirstMainWindow *ui;
    StateWidget *stateWi;
    Newstatewidget *newStateWi;
    corewindowform *coreWindow;
    InputDataWidget *inputdatawidget;
    QString Daihao;
    database *dabase;//数据库对象指针
    QStringList tasknumber;//任务代号数据
    TaskStatePage *taskStatePage;
};

#endif // FIRSTMAINWINDOW_H
