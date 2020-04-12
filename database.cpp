#include "database.h"

database::database()
{

}
//建立一个数据库连接
QSqlDatabase database::createConnection()
{
    //用"sqlite1"与数据库进行连接了
    db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
    db.setDatabaseName(".//qtDb.db");
    if(!db.open())
    {
        qDebug() << "无法建立数据库连接";
        //return ;//优化（1）
    }
    return db;
}

//创建SCMM630-X的数据库表
bool database::createSCMM630Table()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);

    bool success = query.exec("create table SCMM630Table(id INTEGER PRIMARY KEY AUTOINCREMENT,eqName varchar(15),eqType varchar(4),eqSubType varchar(4),eqNumber varchar(4),"
                              "parameterType varchar(4),sendRate varchar(10),modulationEncoding varchar(25),transmissioncarryRate varchar(10),"
                              "transmissioncarryLevel varchar(10),carrierTransmission varchar(5),recivedRate varchar(10),recivedFrequency varchar(10),"
                              "demodulationDecoding varchar(25),recivedLevel varchar(10),EbNo varchar(10),decodingLocking varchar(5))");
    if(success)
    {
        qDebug() << QObject::tr("SCMM630Table数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("SCMM630Table数据库表创建失败！\n")<<query.lastError();
        return false;
    }
}
//插入数据到SCMM630-X的数据库表中
bool database::insertSCMM630_data(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString sendRate,QString modulationEncoding,QString transmissioncarryRate,QString transmissioncarryLevel,QString carrierTransmission,QString recivedRate,QString recivedFrequency,QString demodulationDecoding,QString recivedLevel,QString EbNo,QString decodingLocking){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into SCMM630Table values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    //query.bindValue(0,NULL);
    query.bindValue(1, eqName);
    query.bindValue(2, eqType);
    query.bindValue(3, eqSubType);
    query.bindValue(4, eqNumber);
    query.bindValue(5, parameterType);
    query.bindValue(6, sendRate);
    query.bindValue(7, modulationEncoding);
    query.bindValue(8, transmissioncarryRate);
    query.bindValue(9, transmissioncarryLevel);
    query.bindValue(10, carrierTransmission);
    query.bindValue(11, recivedRate);
    query.bindValue(12,recivedFrequency);
    query.bindValue(13, demodulationDecoding);
    query.bindValue(14, recivedLevel);
    query.bindValue(15, EbNo);
    query.bindValue(16, decodingLocking);
    bool success=query.exec();
    if(!success)
      {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("保存失败"));
            return false;
        }
    return true;

}
//删除SCMM630-X的数据库表
bool database::deleteSCMM630Table(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("drop table SCMM630Table");
    //query.exec("drop table IntermediatefrequencyTable");
   if(query.exec())
   {
       qDebug() << query.lastError();
       return false;
   }
   else
   {
       qDebug() << "SCMM630-X的数据库表已经删除";
       return true;
   }
}
//查询数据表数据
bool database::querySCMM630data()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from SCMM630Table");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("SCMM630Table表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {

        for(int i=0;i<17;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
        }

    }
    qDebug() <<TasknumberList<<endl;
    return true;
}

//创建中频单元-1的数据库表
bool database::createIntermediate_frequency_unit(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("create table IntermediatefrequencyTable(id INTEGER PRIMARY KEY AUTOINCREMENT,eqName varchar(15),eqType varchar(4),eqSubType varchar(4),eqNumber varchar(4),parameterType varchar(4),onesendattenuation varchar(10),twosendattenuation varchar(10),threesendattenuation varchar(10),foursendattenuation varchar(10),onerecivedattenuation varchar(10),tworecivedattenuation varchar(10),threerecivedattenuation varchar(10),fourrecivedattenuation varchar(10))");
    if(success)
    {
        qDebug() << QObject::tr("IntermediatefrequencyTable数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("IntermediatefrequencyTable数据库表创建失败！\n")<<query.lastError();
        return false;
    }
}
bool database::queryIntermediate_frequency_unitdata(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from IntermediatefrequencyTable");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("IntermediatefrequencyTable表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {

        for(int i=0;i<13;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
        }

    }
    qDebug() <<TasknumberList<<endl;
    return true;
}
bool database::insertIntermediate_frequency_unit(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString onesendattenuation,QString twosendattenuation,QString threesendattenuation,QString foursendattenuation,
                                                 QString onerecivedattenuation ,QString tworecivedattenuation ,QString threerecivedattenuation ,QString fourrecivedattenuation){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into IntermediatefrequencyTable values(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    //query.bindValue(0,NULL);
    query.bindValue(1,eqName);
    query.bindValue(2,eqType);
    query.bindValue(3,eqSubType);
    query.bindValue(4,eqNumber);
    query.bindValue(5,parameterType);
    query.bindValue(6, onesendattenuation);
    query.bindValue(7, twosendattenuation);
    query.bindValue(8, threesendattenuation);
    query.bindValue(9, foursendattenuation);
    query.bindValue(10, onerecivedattenuation);
    query.bindValue(11, tworecivedattenuation);
    query.bindValue(12, threerecivedattenuation);
    query.bindValue(13, fourrecivedattenuation);
    bool success=query.exec();
    if(!success)
      {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("保存失败"));
            return false;
        }
    return true;
}

bool database::deletIntermediate_frequency_unit(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("drop table IntermediatefrequencyTable");
   if(query.exec())
   {
       qDebug() << query.lastError();
       return false;
   }
   else
   {
       qDebug() << "Intermediatefrequency的数据库表已经删除";
       return true;
   }
}
//UTDT_4505系类表操作
bool database::createUTDT_4505Table(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("create table UTDT_4505Table(id INTEGER PRIMARY KEY AUTOINCREMENT,eqName varchar(15),eqType varchar(4),eqSubType varchar(4),eqNumber varchar(4),parameterType varchar(4),frequency varchar(15),attenuation varchar(10),alarmState varchar(10),remoteControl varchar(10),fifteenVotage varchar(10),fourteenVotage varchar(10),vccVotage varchar(10),fiveExpressVotage varchar(10),temperature varchar(10),sumLoopTuning varchar(10))");
   if(success)
    {
        qDebug() << QObject::tr("UTDT_4505Table数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("UTDT_4505Table数据库表创建失败！\n")<<query.lastError();
        return false;
    }
}
bool database::insertUTDT_4505data(QString eqName, QString eqType, QString eqSubType, QString eqNumber,
                                   QString parameterType, QString frequency, QString attenuation,
                                   QString alarmState, QString remoteControl, QString fifteenVotage,
                                   QString fourteenVotage, QString vccVotage, QString fiveExpressVotage,
                                   QString temperature, QString sumLoopTuning){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into UTDT_4505Table values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    //query.bindValue(0,NULL);
    query.bindValue(1,eqName);
    query.bindValue(2,eqType);
    query.bindValue(3,eqSubType);
    query.bindValue(4,eqNumber);
    query.bindValue(5,parameterType);
    query.bindValue(6, frequency);
    query.bindValue(7, attenuation);
    query.bindValue(8, alarmState);
    query.bindValue(9, remoteControl);
    query.bindValue(10, fifteenVotage);
    query.bindValue(11, fourteenVotage);
    query.bindValue(12, vccVotage);
    query.bindValue(13, fiveExpressVotage);
    query.bindValue(14, temperature);
    query.bindValue(15, sumLoopTuning);
    bool success=query.exec();
    if(!success)
      {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("保存失败"));
            return false;
        }
    return true;
}
bool database::queryUTDT_4505data()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from UTDT_4505Table");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("UTDT_4505Table表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {

        for(int i=0;i<16;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
        }

    }
    qDebug() <<TasknumberList<<endl;
    return true;
}

bool database::deleteUTDT_4505Table()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("drop table UTDT_4505Table");
   if(query.exec())
   {
       qDebug() << query.lastError();
       return false;
   }
   else
   {
       qDebug() << "UTDT_4505Table的数据库表已经删除";
       return true;
   }
}
//ComtechPST系类表操作
bool database::createComtechPSTTable()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success = query.exec("create table ComtechPSTTable(id INTEGER PRIMARY KEY AUTOINCREMENT,eqName varchar(15),eqType varchar(4),eqSubType varchar(4),eqNumber varchar(4),parameterType varchar(4),RFSwitch varchar(10),attenuation varchar(10),redundantMode varchar(10),radiofrequencySuppression varchar(10),onlineState varchar(10),fivteensupplyPower varchar(10),seventPointFivesupplyPower varchar(10),fivesupplyPower varchar(10),negativefiveupplyPower varchar(10),rfPS1 varchar(10),rfPS2 varchar(10),TMP1 varchar(10),TMP2 varchar(10),forwardPower varchar(10),backwardPower varchar(10))");
   if(success)
    {
        qDebug() << QObject::tr("ComtechPSTTable数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("ComtechPSTTable数据库表创建失败！\n")<<query.lastError();
        return false;
    }
}
bool database::insertComtechPSTdata(QString eqName, QString eqType, QString eqSubType, QString eqNumber, QString parameterType,
                                    QString RFSwitch, QString attenuation, QString redundantMode, QString radiofrequencySuppression,
                                    QString onlineState, QString fivteensupplyPower, QString seventPointFivesupplyPower,
                                    QString fivesupplyPower, QString negativefiveupplyPower, QString rfPS1, QString rfPS2,
                                    QString TMP1, QString TMP2, QString forwardPower, QString backwardPower){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into ComtechPSTTable values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    //query.bindValue(0,NULL);
    query.bindValue(1,eqName);
    query.bindValue(2,eqType);
    query.bindValue(3,eqSubType);
    query.bindValue(4,eqNumber);
    query.bindValue(5,parameterType);
    query.bindValue(6, RFSwitch);
    query.bindValue(7, attenuation);
    query.bindValue(8, attenuation);
    query.bindValue(9, redundantMode);
    query.bindValue(10, radiofrequencySuppression);
    query.bindValue(11, onlineState);
    query.bindValue(12, fivteensupplyPower);
    query.bindValue(13, seventPointFivesupplyPower);
    query.bindValue(14, fivesupplyPower);
    query.bindValue(15, negativefiveupplyPower);
    query.bindValue(16, rfPS1);
    query.bindValue(17, rfPS2);
    query.bindValue(18, TMP1);
    query.bindValue(19, TMP2);
    query.bindValue(20, forwardPower);
    query.bindValue(21, backwardPower);
    bool success=query.exec();
    if(!success)
      {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("保存失败"));
            return false;
        }
    return true;
}

bool database::queryComtechPSTdata()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from ComtechPSTTable");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("ComtechPSTTable表字段数：" ) << rec.count();
    QStringList TasknumberList=QStringList();
    while(query.next())
    {

        for(int i=0;i<22;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
        }

    }
    qDebug() <<TasknumberList<<endl;
    return true;
}
bool database::deteleComtechPSTTable(){
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("drop table ComtechPSTTable");
   if(query.exec())
   {
       qDebug() << query.lastError();
       return false;
   }
   else
   {
       qDebug() << "ComtechPSTTable的数据库表已经删除";
       return true;
   }
}
//创建数据库表
bool database::createTable()
{
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);

    bool success = query.exec("create table TaskDaiHaoTable(tasknumber varchar(15),sendingpointfre varchar(15),modulationstyle varchar(50),sendingrate int,receivepointfre varchar(15),demodulationstyle varchar(30),receiveingrate int)");
    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！\n");
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
    ///未检测Tasknum是否为空，Tasknumber应该是主键，不能为空,在界面已经检查

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
    //qDebug() << QObject::tr("TaskDaiHaoTable表字段数：" ) << rec.count();
    while(query.next())
    {
        for(int i=0;i<7;i++)
        {
            QString s=query.value(i).toString();
           // qDebug() << s << "-";
            TasknumberList.insert(i,s);
        }

    }
    return TasknumberList;
    }
}
//查询TaskDaiHaoTable所有数据
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

        for(int i=0;i<17;i++)
        {
            QString s=query.value(i).toString();
            TasknumberList.append(s);
        }

    }
    qDebug() <<TasknumberList<<endl;
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
