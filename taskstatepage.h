#ifndef TASKSTATEPAGE_H
#define TASKSTATEPAGE_H

#include <QWidget>
#include"database.h"
namespace Ui {
class TaskStatePage;
}

class TaskStatePage : public QWidget
{
    Q_OBJECT

public:
    explicit TaskStatePage(QWidget *parent = nullptr);
    ~TaskStatePage();
    void RefreshData(QString);
    void SelectTaskNumber();
    void SaveTaskQuickPhoto();

private:
    Ui::TaskStatePage *ui;
    int row;
    int column;
    database *dabase;

};

#endif // TASKSTATEPAGE_H
