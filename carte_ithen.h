#ifndef CARTE_ITHEN_H
#define CARTE_ITHEN_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino_alarm.h"
#include <QObject>


namespace Ui {
class carte_ithen;
}

class carte_ithen : public QDialog
{
    Q_OBJECT

public:
    explicit carte_ithen(QWidget *parent = nullptr);
    ~carte_ithen();
private slots:
    void on_allumer_clicked();
    void update_label();
    void on_arreter_clicked();

    void on_activer_clicked();

private:
    Ui::carte_ithen *ui;
    arduino_code A;
    QByteArray data;

;
};

#endif // CARTE_ITHEN_H
