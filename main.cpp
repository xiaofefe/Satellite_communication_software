#include "firstmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstMainWindow w;
    w.setWindowTitle("任务状态选择");
    w.show();

    return a.exec();
}
