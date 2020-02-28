#ifndef DEVICEBUTTON_H
#define DEVICEBUTTON_H

#include <QObject>
#include <QPushButton>


class DeviceButton : public QPushButton
{
     Q_OBJECT

public:
   explicit DeviceButton(QWidget *parent = nullptr);
    ~DeviceButton();
private:
    //Device dev_info;

    QString ShowDevInfo();

protected:
    //bool event(QEvent *e) override;

};

#endif // DEVICEBUTTON_H
