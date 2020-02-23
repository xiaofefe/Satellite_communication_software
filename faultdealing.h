#ifndef FAULTDEALING_H
#define FAULTDEALING_H

#include <QWidget>

namespace Ui {
class FaultDealing;
}

class FaultDealing : public QWidget
{
    Q_OBJECT

public:
    explicit FaultDealing(QWidget *parent = nullptr);
    ~FaultDealing();

private:
    Ui::FaultDealing *ui;
};

#endif // FAULTDEALING_H
