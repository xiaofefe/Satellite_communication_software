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
    QSqlDatabase createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    //SCMM630系类表
    bool createSCMM630Table();
    bool insertSCMM630_data(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString sendRate,QString modulationEncoding,QString transmissioncarryRate,QString transmissioncarryLevel,QString carrierTransmission,QString recivedRate,QString recivedFrequency,QString demodulationDecoding,QString recivedLevel,QString EbNo,QString decodingLocking);
    bool deleteSCMM630Table();
    bool querySCMM630data();
    //中频单元系类表
    bool createIntermediate_frequency_unit();
    bool insertIntermediate_frequency_unit(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString onesendattenuation,QString twosendattenuation,QString threesendattenuation,QString foursendattenuation,
                                           QString onerecivedattenuation ,QString tworecivedattenuation ,QString threerecivedattenuation ,QString fourrecivedattenuation);
    bool queryIntermediate_frequency_unitdata();
    bool deletIntermediate_frequency_unit();
   //UTDT_4505系类表
    bool createUTDT_4505Table();
    bool insertUTDT_4505data(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString frequency,QString attenuation,QString alarmState,QString remoteControl,QString fifteenVotage,QString fourteenVotage,QString vccVotage,QString fiveExpressVotage,QString temperature,QString sumLoopTuning);
    bool queryUTDT_4505data();
    bool deleteUTDT_4505Table();
   //ComtechPSTTable系类表
    bool createComtechPSTTable();
    bool insertComtechPSTdata(QString eqName,QString eqType ,QString eqSubType,QString eqNumber,QString parameterType,QString RFSwitch,QString attenuation,QString redundantMode,QString radiofrequencySuppression,QString onlineState,QString fivteensupplyPower,QString seventPointFivesupplyPower,
                              QString fivesupplyPower,QString negativefiveupplyPower,QString rfPS1,QString rfPS2,QString TMP1,QString TMP2,QString forwardPower,QString backwardPower);
    bool queryComtechPSTdata();
    bool deteleComtechPSTTable();


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
