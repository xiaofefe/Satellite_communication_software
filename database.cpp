#include "database.h"

database::database()
{

}
//建立一个数据库连接
bool database::createConnection()
{
    //以后就可以用"sqlite1"与数据库进行连接了
    db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
    db.setDatabaseName(".//qtDb.db");
    if(!db.open())
    {
        qDebug() << "无法建立数据库连接";
        return false;
    }
    return true;
}
//创建数据库表
bool database::createTable()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
   //bool success = query.exec("delete from TaskDaiHaoTable");
   bool success = query.exec("create table TaskDaiHaoTable(tasknumber varchar(15),sendingpointfre varchar(15),modulationstyle varchar(50),sendingrate int,receivepointfre varchar(15),demodulationstyle varchar(30),receiveingrate int)");
    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！\n");
        //qDebug() << QObject::tr("数据库表删除成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("数据库表创建失败！\n")<<query.lastError();
        return false;
    }
}
//插入一条记录
bool database::insert(QString Tasknumber,QString sendingpointfre, QString modulationstyle,int sendingrate,QString receivepointfre,QString demodulationstyle,int receiveingrate)
{
    //未检测Tasknum是否为空，Tasknumber应该是主键，不能为空

    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into TaskDaiHaoTable values(?,?,?,?,?,?,?)");
    query.bindValue(0, Tasknumber);
    query.bindValue(1, sendingpointfre);
    query.bindValue(2, modulationstyle);
    query.bindValue(3, sendingrate);
    query.bindValue(4, receivepointfre);
    query.bindValue(5, demodulationstyle);
    query.bindValue(6, receiveingrate);
    bool success=query.exec();
    if(!success)
      {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("保存失败"));
            return false;
        }
    return true;
}
//查询所有任务代号信息
QStringList database::queryTasknumbersAll()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from TaskDaiHaoTable");
    QSqlRecord rec = query.record();
    //qDebug() << QObject::tr("TaskDaiHaoTable表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {
        int i=0;
        QString s=query.value(0).toString();
        //qDebug() << s << " ";
        TasknumberList.insert(i,s);
    }
    return TasknumberList;
}
//查询数据库中某一记录
QStringList database::queryByTasknumberAll(QString s)
{
    //未查询是否为空

    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    QStringList TasknumberList=QStringList();
    bool success=query.exec(QString("select * from TaskDaiHaoTable where tasknumber='%1'").arg(s));
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("查找失败"));
        TasknumberList.insert(0,"查找失败");
        return TasknumberList;
    }else
    {
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("TaskDaiHaoTable表字段数：" ) << rec.count();
    while(query.next())
    {
        for(int i=0;i<7;i++)
        {
            QString s=query.value(i).toString();
            qDebug() << s << "-";
            TasknumberList.insert(i,s);
        }

    }
    return TasknumberList;
    }
}
//查询所有数据
bool database::queryAll()
{

    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from TaskDaiHaoTable");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("TaskDaiHaoTable表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {
        for(int i=0;i<7;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
            qDebug() <<TasknumberList<<endl;
        }

    }
//    for(int i=0;i<TasknumberList.length();i++)
//    {
//     qDebug() <<"第"<<i<<"条数据"<< TasknumberList[i]<<endl;
//    }
    return true;
}

//删除任务表
bool database::deleteTableTasknumber()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("drop table TaskDaiHaoTable");
   if(query.exec())
   {
       qDebug() << query.lastError();

       return false;
   }
   else
   {
       qDebug() << "table cleared";
       return true;
   }
}

//更新任务表
bool database::UpdataDatabase(QString Tasknumber1,QString sendingpointfre1, QString modulationstyle1,int sendingrate1,QString receivepointfre1,QString demodulationstyle1,int receiveingrate1)
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);

    //构造更新字符串
    QString que_str =" UPDATE TaskDaiHaoTable SET sendingpointfre=:sendingpointfre1,modulationstyle=:modulationstyle1,sendingrate=:sendingrate1, \
            receivepointfre=:receivepointfre1,demodulationstyle=:demodulationstyle1,receiveingrate=:receiveingrate1 where tasknumber='%1'";
    query.prepare(que_str.arg(Tasknumber1));


    //绑定参数值
    query.bindValue(":sendingpointfre1",sendingpointfre1);
    query.bindValue(":modulationstyle1",modulationstyle1);
    query.bindValue(":sendingrate1",sendingrate1);
    query.bindValue(":receivepointfre1",receivepointfre1);
    query.bindValue(":demodulationstyle1",demodulationstyle1);
    query.bindValue(":receiveingrate1",receiveingrate1);

    qDebug()<<sendingpointfre1<<"-"<<modulationstyle1<<"-"<<sendingpointfre1<<"-"<<receiveingrate1;


    bool success=query.exec();

    if(!success)
     {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
        return false;
     }
    return true;
}

//关闭表
void database::CloseDatabase(database b)
{
    if(b.db.isValid())
    {
        b.db.close();
        qDebug()<<"数据库关闭成功";
    }
}
