#ifndef NEWSTATEWIDGET_H
#define NEWSTATEWIDGET_H

#include <QWidget>

namespace Ui {
class Newstatewidget;
}

class Newstatewidget : public QWidget
{
    Q_OBJECT

public:
    explicit Newstatewidget(QWidget *parent = nullptr);
    ~Newstatewidget();
     void SendSignal();
     void clearNewStateData();
signals:
    void TurntoFirstWindow();
private slots:
    void on_pushButton_clicked();
    void doSelectFont(QString);
    void doSelectFont1(QString);
private:
    Ui::Newstatewidget *ui;
    QString modulationstyle;
    QString demodulationstyle;
    QString Tasknumber;
    QString sendingpointfre;
    QString sendingrate;
    QString receivepointfre;
    QString receiveingrate;
};

#endif // NEWSTATEWIDGET_H
