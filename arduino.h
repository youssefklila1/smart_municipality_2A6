#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino_alarm.h"
#include <QObject>


namespace Ui {
class arduino;
}

class arduino : public QDialog
{
    Q_OBJECT

public:
    explicit arduino(QWidget *parent = nullptr);
    ~arduino();

private slots:
    void on_allumer_clicked();
    void update_label();
    void on_arreter_clicked();

    void on_activer_clicked();

private:
    Ui::arduino *ui;
    arduino_code A;
    QByteArray data;
};

#endif // ARDUINO_H
