#ifndef TASKSTATUS_H
#define TASKSTATUS_H

#include <QWidget>

namespace Ui {
class Taskstatus;
}

class Taskstatus : public QWidget
{
    Q_OBJECT

public:
    explicit Taskstatus(QWidget *parent = nullptr);
    ~Taskstatus();

private:
    Ui::Taskstatus *ui;
};

#endif // TASKSTATUS_H
