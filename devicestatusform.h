#ifndef DeviceStatusForm_H
#define DeviceStatusForm_H

#include <QWidget>
#include <QModelIndex>

namespace Ui
{
class DeviceStatusForm;
}

class DeviceStatusForm : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceStatusForm(QWidget *parent = 0);
    ~DeviceStatusForm();

    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::DeviceStatusForm *ui;

    void InstallFiller();       //给各个控件安装过滤器

private slots:
    void initForm();


};

#endif // DeviceStatusForm_H
