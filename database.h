#ifndef DATABASE_H
#define DATABASE_H
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

class database
{
public:
    database();
    //任务代号 数据库
    bool createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    bool insert(QString Tasknumber,QString sendingpointfre, QString modulationstyle,int sendingrate,QString receivepointfre,QString demodulationstyle,int receiveingrate);            //插入代号数据
    QStringList queryTasknumbersAll();          //查询所有任务信息
    QStringList queryByTasknumberAll(QString Tasknumber);//根据任务代号查询所有信息
    bool queryAll();
    bool updateById(int id);  //更新
    bool deleteById(int id);  //删除
    bool deleteTableTasknumber();//删除数据库
    void CloseDatabase(database db);
    bool UpdataDatabase(QString Tasknumber,QString sendingpointfre, QString modulationstyle,int sendingrate,QString receivepointfre,QString demodulationstyle,int receiveingrate);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
