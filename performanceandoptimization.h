#ifndef PERFORMANCEANDOPTIMIZATION_H
#define PERFORMANCEANDOPTIMIZATION_H

#include <QWidget>

namespace Ui {
class Performanceandoptimization;
}

class Performanceandoptimization : public QWidget
{
    Q_OBJECT

public:
    explicit Performanceandoptimization(QWidget *parent = nullptr);
    ~Performanceandoptimization();

private:
    Ui::Performanceandoptimization *ui;
};

#endif // PERFORMANCEANDOPTIMIZATION_H
