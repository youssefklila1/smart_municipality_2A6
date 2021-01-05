#include "carte_ithen.h"
#include "ui_carte_ithen.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include<QObject>


carte_ithen::carte_ithen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carte_ithen)
{
    A.connect_arduino();
    ui->setupUi(this);
}

carte_ithen::~carte_ithen()
{
    delete ui;
    ui->setupUi(this);
    int ret=A.connect_arduino();    //lancer arduino

    switch(ret)
    {
    case(0):qDebug()<<"arduino is connected and availeble"<<A.getarduino_port_name();   break;
    case(1):qDebug()<<"arduino is not connected and is availeble"<<A.getarduino_port_name();    break;
    case(-1):qDebug()<<"arduino is not available";
    }

QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT( update_label()));

}

void carte_ithen::on_allumer_clicked()
{
A.write_to_arduino("1");
}

void carte_ithen::on_arreter_clicked()
{
A.write_to_arduino("0");
}

void carte_ithen::on_activer_clicked()
{
    A.write_to_arduino("2");
}

void carte_ithen::update_label()
{

    data=A.read_from_arduino();

    qDebug()<<data<<"valeur arduino ";

     if (data=="2")
    {
    ui->label_2->setText("mouvement detecter");
    }
    else if (data=="1")
    {
    ui->label_2->setText("lampe et buzzeur allumé");
     }
     else if (data=="0")
    {
    ui->label_2->setText("OFF");
     }
     else if (data=="4")
       ui->label_2->setText("pas de mouvement detecter");

}
