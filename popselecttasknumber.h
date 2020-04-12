#ifndef POPSELECTTASKNUMBER_H
#define POPSELECTTASKNUMBER_H

#include <QWidget>

namespace Ui {
class PopSelectTaskNumber;
}

class PopSelectTaskNumber : public QWidget
{
    Q_OBJECT

public:
    explicit PopSelectTaskNumber(QWidget *parent = nullptr);
    ~PopSelectTaskNumber();
    void InitWidgetData();
public slots:
     void doSelectNumber(QString);
     void CancelWidget();
     void GetNumber();
private:
    Ui::PopSelectTaskNumber *ui;
    QString STaskNumber;
};

#endif // POPSELECTTASKNUMBER_H
