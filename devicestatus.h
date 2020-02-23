#ifndef DEVICESTATUS_H
#define DEVICESTATUS_H

#include <QWidget>

namespace Ui {
class Devicestatus;
}

class Devicestatus : public QWidget
{
    Q_OBJECT

public:
    explicit Devicestatus(QWidget *parent = nullptr);
    ~Devicestatus();

private:
    Ui::Devicestatus *ui;
};

#endif // DEVICESTATUS_H
