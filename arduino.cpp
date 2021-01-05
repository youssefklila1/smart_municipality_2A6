#include "arduino.h"
#include "ui_arduino.h"
#include "arduino_alarm.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include<QObject>



arduino::arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduino)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();    //lancer arduino
    A.read_from_arduino();

    switch(ret)
    {
    case(0):qDebug()<<"arduino is connected and availeble"<<A.getarduino_port_name();   break;
    case(1):qDebug()<<"arduino is not connected and is availeble"<<A.getarduino_port_name();    break;
    case(-1):qDebug()<<"arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}


arduino::~arduino()
{
    delete ui;
}

void arduino::update_label()
{

data=A.read_from_arduino();

qDebug()<<data<<"valeur arduino ";

 if (data=="2")
{
ui->label_3->setText("mouvement detecter");
}
else if (data=="1")
{
ui->label_3->setText("lampe et buzzeur allumé");
 }
 else if (data=="0")
{
ui->label_3->setText("OFF");
 }
 else if (data=="4")
   ui->label_3->setText("pas de mouvement detecter");
}

void arduino::on_arreter_clicked()
{
A.write_to_arduino("0");
}

void arduino::on_allumer_clicked()
{
A.write_to_arduino("1");
}

void arduino::on_activer_clicked()
{
 A.write_to_arduino("2");
}
