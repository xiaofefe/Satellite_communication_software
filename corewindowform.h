#ifndef COREWINDOWFORM_H
#define COREWINDOWFORM_H

#include <QWidget>

namespace Ui {
class corewindowform;
}

class corewindowform : public QWidget
{
    Q_OBJECT

public:
    explicit corewindowform(QWidget *parent = nullptr);
    ~corewindowform();
    void InitCoreForm();
    void SendCancel();
signals:
       void CancelSignal();
private slots:
       void on_navListView_pressed(const QModelIndex &index);
private:
    Ui::corewindowform *ui;
};

#endif // COREWINDOWFORM_H
