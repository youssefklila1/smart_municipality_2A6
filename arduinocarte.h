#ifndef ARDUINOCARTE_H
#define ARDUINOCARTE_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>

class arduinoCarte
{
public:
    arduinoCarte();

    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);//envoyer des informations à la carte arduino
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();

private:
    QSerialPort* serial;//objet pour utiliser les classes QSerial...
    QByteArray data;//ou ont va sauvegarder les informations
    QString arduino_port_name;
    bool arduino_is_available; //verifier si la carte est connecte au pc ou non
    static const quint16 arduino_uno_vendor_id=9025;//le fabricant
    static const quint16 arduino_uno_product_id=67;//le produit



};

#endif // ARDUINOCARTE_H
