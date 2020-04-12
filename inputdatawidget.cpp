#include "inputdatawidget.h"
#include "ui_inputdatawidget.h"
#include<QMessageBox>
InputDataWidget::InputDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputDataWidget)
{
    ui->setupUi(this);
    dabase=new database();//创建数据库对象
    QStringList data={"SCMM630-1","SCMM630-2","中频单元-1","UT-4505-1","UT-4505-2","DT-4503-1","DT-4503-2","ComtechPST-1","ComtechPST-2"};
    QStringList CodeSytle={"16APSK LDPC 3/4"};
    QStringList EncodeingStyle={"QPSK_LDPC_3/4"};
    QStringList OpenOrClose={"开","关"};
    QStringList LockOr={"锁定","未锁定"};
    QStringList RFSwitch={"开","关"};
    QStringList radiofrequencySuppression={"手动","自动"};
    QStringList onlineState={"离线","在线"};
    ui->comboBox->addItems(data);
    if(ui->comboBox->currentIndex()==0)
    {
        ui->frame_2->setVisible(false);
        ui->frame_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame->setVisible(true);
    }
    ui->comboBox_2->addItems(CodeSytle);
    ui->comboBox_3->addItems(OpenOrClose);
    ui->comboBox_4->addItems(EncodeingStyle);
    ui->comboBox_5->addItems(LockOr);
    ui->comboBox_6->addItems(RFSwitch);
    ui->comboBox_7->addItems(radiofrequencySuppression);
    ui->comboBox_8->addItems(onlineState);
    QSqlDatabase db=dabase->createConnection();//创建数据库

    //删除数据库表在这儿
    //dabase->deleteSCMM630Table();
    //dabase->deleteUTDT_4505Table();
    //dabase->deletIntermediate_frequency_unit();
    //dabase->deteleComtechPSTTable();


    //创建SCMM630数据表
    dabase->deleteSCMM630Table();
    QSqlQuery query(db);
   if(db.tables().contains("SCMM630Table"))//判断表是否存在
    {         qDebug()<<"SCMM630数据表已经创建"<<endl;
    }else
   {
         dabase->createSCMM630Table();//不需要每一次都创建数据表，第一次就ok
    }
   if(db.tables().contains("IntermediatefrequencyTable"))//判断表是否存在
    {         qDebug()<<"IntermediatefrequencyTable数据表已经创建"<<endl;
    }else
   {
         dabase->createIntermediate_frequency_unit();//不需要每一次都创建数据表，第一次就ok
    }
   if(db.tables().contains("UTDT_4505Table"))//判断表是否存在
    {         qDebug()<<"UTDT_4505Table数据表已经创建"<<endl;
    }else
   {
         dabase->createUTDT_4505Table();//不需要每一次都创建数据表，第一次就ok
    }
   if(db.tables().contains("ComtechPSTTable"))//判断表是否存在
    {         qDebug()<<"ComtechPSTTable数据表已经创建"<<endl;
    }else
   {
         dabase->createComtechPSTTable();//不需要每一次都创建数据表，第一次就ok
    }
    //触发下拉选择名称框
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectTaskName(QString)));
    connect(ui->pushButton_2,&QPushButton::pressed,this,&InputDataWidget::saveSCMM630data);
    connect(ui->pushButton_3,&QPushButton::pressed,this,&InputDataWidget::saveintermediatefrequencyunitdata);
    connect(ui->pushButton_4,&QPushButton::pressed,this,&InputDataWidget::saveUTDT_4505Table);
    connect(ui->pushButton_5,&QPushButton::pressed,this,&InputDataWidget::saveComtechPSTdata);
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectCodeing(QString)));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectOpenOrClose(QString)));
    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectEncoding(QString)));
    connect(ui->comboBox_5,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectLocking(QString)));
    connect(ui->comboBox_6,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectRFSwitch(QString)));
    connect(ui->comboBox_7,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectradiofrequencySuppression(QString)));
    connect(ui->comboBox_8,SIGNAL(currentIndexChanged(QString)),this,SLOT(doSelectonlineState(QString)));
    connect(ui->pushButton,&QPushButton::clicked,this,&InputDataWidget::SendSignal);

}
void InputDataWidget::SendSignal()
{
    emit TurntoFirstWindow();
}
void InputDataWidget::saveComtechPSTdata(){
     QString eqType,eqSubType,eqNumber,parameterType;
     QString attenuation,redundantMode,fivteensupplyPower,seventPointFivesupplyPower,
             fivesupplyPower,negativefiveupplyPower,rfPS1,rfPS2,TMP1,TMP2,forwardPower,backwardPower;
     if(ui->comboBox_6->currentIndex()==0)
     {
         //RFSwitch,radiofrequencySuppression,onlineState
         RFSwitch=ui->comboBox_6->currentText();
     }
     if(ui->comboBox_7->currentIndex()==0)
     {
         //RFSwitch,radiofrequencySuppression,onlineState
         radiofrequencySuppression=ui->comboBox_6->currentText();
     }
     if(ui->comboBox_8->currentIndex()==0)
     {
         //RFSwitch,radiofrequencySuppression,onlineState
         onlineState=ui->comboBox_6->currentText();
     }

     QMessageBox *mess= new QMessageBox();
     attenuation=ui->lineEdit_30->text();
     redundantMode=ui->lineEdit_31->text();
     fivteensupplyPower=ui->lineEdit_32->text();
     seventPointFivesupplyPower=ui->lineEdit_33->text();
     fivesupplyPower=ui->lineEdit_38->text();
     negativefiveupplyPower=ui->lineEdit_39->text();
     rfPS1=ui->lineEdit_40->text();
     rfPS2=ui->lineEdit_41->text();
     TMP1=ui->lineEdit_42->text();
     TMP2=ui->lineEdit_43->text();
     forwardPower=ui->lineEdit_44->text();
     backwardPower=ui->lineEdit_45->text();

     bool f=dabase->insertComtechPSTdata(eqName,eqType,eqSubType,eqNumber,
                                        parameterType,RFSwitch,attenuation,redundantMode,radiofrequencySuppression,onlineState,fivteensupplyPower,seventPointFivesupplyPower,
                                         fivesupplyPower,negativefiveupplyPower,rfPS1,rfPS2,TMP1,TMP2,forwardPower,backwardPower);
     if(f==true)
     {
         dabase->queryComtechPSTdata();
         mess->setText("设备数据保存完毕");
         mess->show();
     }else
     {
         dabase->queryComtechPSTdata();
         //db.CloseDatabase(db);//关闭数据库
         mess->setText("保存失败");
         mess->show();
     }
}
void InputDataWidget::saveUTDT_4505Table(){
    QString eqType,eqSubType,eqNumber,parameterType;
    QString frequency,attenuation,alarmState,remoteControl,fifteenVotage,fourteenVotage,vccVotage,fiveExpressVotage,temperature,sumLoopTuning;
    QMessageBox *mess= new QMessageBox();

    eqType=ui->lineEdit_8->text();
    eqSubType=ui->lineEdit_9->text();
    eqNumber=ui->lineEdit_10->text();
    parameterType=ui->lineEdit_11->text();

    frequency=ui->lineEdit_20->text();
    attenuation=ui->lineEdit_21->text();
    alarmState=ui->lineEdit_22->text();
    remoteControl=ui->lineEdit_23->text();
    fifteenVotage=ui->lineEdit_24->text();
    fourteenVotage=ui->lineEdit_25->text();
    vccVotage=ui->lineEdit_26->text();
    fiveExpressVotage=ui->lineEdit_27->text();
    temperature=ui->lineEdit_28->text();
    sumLoopTuning=ui->lineEdit_29->text();
    bool f=dabase->insertUTDT_4505data(eqName,eqType,eqSubType,eqNumber,
                                       parameterType,frequency,attenuation,alarmState,
                                       remoteControl,fifteenVotage,fourteenVotage,vccVotage,
                                       fiveExpressVotage,temperature,sumLoopTuning);
    if(f==true)
    {
        dabase->queryUTDT_4505data();
        mess->setText("设备数据保存完毕");
        mess->show();
    }else
    {
        dabase->queryUTDT_4505data();
        //db.CloseDatabase(db);//关闭数据库
        mess->setText("保存失败");
        mess->show();
    }
}
void InputDataWidget::saveintermediatefrequencyunitdata(){
    QString eqType,eqSubType,eqNumber,parameterType,onesendattenuation,twosendattenuation,threesendattenuation,foursendattenuation,
   onerecivedattenuation ,tworecivedattenuation ,threerecivedattenuation ,fourrecivedattenuation;
    QMessageBox *mess= new QMessageBox();

    eqType=ui->lineEdit_8->text();
    eqSubType=ui->lineEdit_9->text();
    eqNumber=ui->lineEdit_10->text();
    parameterType=ui->lineEdit_11->text();
    onesendattenuation=ui->lineEdit_12->text();
    twosendattenuation=ui->lineEdit_13->text();
    threesendattenuation=ui->lineEdit_14->text();
    foursendattenuation=ui->lineEdit_15->text();
    onerecivedattenuation=ui->lineEdit_16->text();
    tworecivedattenuation=ui->lineEdit_17->text();
    threerecivedattenuation=ui->lineEdit_18->text();
    fourrecivedattenuation=ui->lineEdit_19->text();
    bool f=dabase->insertIntermediate_frequency_unit(eqName,eqType,eqSubType,eqNumber,parameterType,onesendattenuation,twosendattenuation,threesendattenuation,foursendattenuation,
                                              onerecivedattenuation ,tworecivedattenuation ,threerecivedattenuation ,fourrecivedattenuation);
    if(f==true)
    {
        dabase->queryIntermediate_frequency_unitdata();
        mess->setText("设备数据保存完毕");
        mess->show();
    }else
    {
        dabase->queryIntermediate_frequency_unitdata();
        //db.CloseDatabase(db);//关闭数据库
        mess->setText("保存失败");
        mess->show();
    }

}
void InputDataWidget::saveSCMM630data(){
    //if(ui->lineEdit.isEmpyt())
    QString eqType,eqSubType,eqNumber,parameterType,sendRate,transmissioncarryRate,
            transmissioncarryLevel,recivedRate,recivedFrequency,
               recivedLevel, EbNo;
     QMessageBox *mess= new QMessageBox();
    if(ui->comboBox->currentIndex()==0)
    {
        eqName=ui->comboBox->currentText();
    }
    if(ui->comboBox_2->currentIndex()==0)
    {
        modulationEncoding=ui->comboBox_2->currentText();
    }
    if(ui->comboBox_3->currentIndex()==0)
    {
        carrierTransmission=ui->comboBox_3->currentText();
    }
    if(ui->comboBox_4->currentIndex()==0)
    {
        demodulationDecoding=ui->comboBox_4->currentText();
    }
    if(ui->comboBox_5->currentIndex()==0)
    {
        decodingLocking=ui->comboBox_5->currentText();
    }
    eqType=ui->lineEdit_8->text();
    eqSubType=ui->lineEdit_9->text();
    eqNumber=ui->lineEdit_10->text();
    parameterType=ui->lineEdit_11->text();

    sendRate=ui->lineEdit->text();
    transmissioncarryRate=ui->lineEdit_2->text();
    transmissioncarryLevel=ui->lineEdit_3->text();
    recivedRate=ui->lineEdit_4->text();
    recivedFrequency=ui->lineEdit_5->text();
    recivedLevel=ui->lineEdit_6->text();
    EbNo=ui->lineEdit_7->text();
    //database db=database();
    bool f=dabase->insertSCMM630_data(eqName,eqType,eqSubType,eqNumber,parameterType,sendRate,modulationEncoding,transmissioncarryRate,
                                 transmissioncarryLevel,carrierTransmission,recivedRate,recivedFrequency,
                                     demodulationDecoding, recivedLevel, EbNo,decodingLocking);
    if(f==true)
    {
        dabase->queryAll();
        mess->setText("设备数据保存完毕");
        mess->show();
    }else
    {
        dabase->queryAll();
        //db.CloseDatabase(db);//关闭数据库
        mess->setText("保存失败");
        mess->show();
    }
}
void InputDataWidget::doSelectRFSwitch(QString s)
{
    //RFSwitch,radiofrequencySuppression,onlineState
   RFSwitch=s;
}
void InputDataWidget::doSelectCodeing(QString s)
{
    radiofrequencySuppression=s;
}
void InputDataWidget::doSelectradiofrequencySuppression(QString s)
{
    onlineState=s;
}
void InputDataWidget::doSelectonlineState(QString s)
{
    modulationEncoding=s;
}
void InputDataWidget::doSelectOpenOrClose(QString s)
{
    carrierTransmission=s;
}
void InputDataWidget::doSelectEncoding(QString s)
{
    demodulationDecoding=s;
}
void InputDataWidget::doSelectLocking(QString s)
{
    decodingLocking=s;
}
void InputDataWidget::doSelectTaskName(QString s)
{

    if(s=="SCMM630-1"||s=="SCMM630-2")
    {
        ui->frame_2->setVisible(false);
        ui->frame_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame->setVisible(true);
        eqName=s;
    }
    else if(s=="中频单元-1")
    {
        ui->frame->setVisible(false);
        ui->frame_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_2->setVisible(true);
        ui->frame_2->setGeometry(20,130,800,600);
        eqName=s;
    }
    else if(s=="UT-4505-1"||s=="UT-4505-2"||s=="DT-4503-1"||s=="DT-4503-2")
    {
        ui->frame->setVisible(false);
        ui->frame_2->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_3->setVisible(true);
        ui->frame_3->setGeometry(20,130,800,600);
        eqName=s;
    }
    else{
        ui->frame->setVisible(false);
        ui->frame_2->setVisible(false);
        ui->frame_3->setVisible(false);
        ui->frame_4->setVisible(true);
        ui->frame_4->setGeometry(20,130,1000,700);
        eqName=s;
    }
 }
InputDataWidget::~InputDataWidget()
{
    delete ui;
}
