#ifndef FIRSTMAINWINDOW_H
#define FIRSTMAINWINDOW_H

#include <QMainWindow>
#include "statewidget.h"
#include "database.h"
#include "newstatewidget.h"
#include "corewindowform.h"
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


    void DoSomethingAboutModiflySignal();
    void DoSomethingAboutNewSignal();
    void DoSomethingAboutCoreMian();
    void TurnToSTateModiflyTaskWidget();
public slots:
     void doSelectFont(QString);
private:
    Ui::FirstMainWindow *ui;
    StateWidget *stateWi;
    Newstatewidget *newStateWi;
    //CoreWindow coreWindow;
    corewindowform coreWindow;
    QString Daihao;
    database *dabase;//数据库对象指针
    QStringList tasknumber;//任务代号数据
};

#endif // FIRSTMAINWINDOW_H
