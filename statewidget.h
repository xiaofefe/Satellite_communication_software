#ifndef STATEWIDGET_H
#define STATEWIDGET_H

#include <QWidget>
namespace Ui {
class StateWidget;
}

class StateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StateWidget(QWidget *parent = nullptr);
    ~StateWidget();
    void SaveState();
    void SendSignal();
    void ObtainData(QString data);

    void FillData();

signals:
    void TurntoFirstWindow();
public slots:
    void doSelectFont(QString);
    void doSelectFont1(QString);
private:
    Ui::StateWidget *ui;
    QString modulationstyle;
    QString demodulationstyle;
    QString Tasknumber;
    QString sendingpointfre;
    QString sendingrate;
    QString receivepointfre;
    QString receiveingrate;
};

#endif // STATEWIDGET_H
