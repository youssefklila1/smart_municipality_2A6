#include "mainwindow.h"
#include "dialog.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Connection c ;
    MainWindow w ;
    bool test =c.createconnect();
    if (test)
     {
       w.show();
       QMessageBox::information(nullptr,QObject::tr("data base is open"),
               QObject::tr("connection succesful.\n"),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr,QObject::tr("data base is not  open"),
                QObject::tr("connection failed.\n"),QMessageBox::Cancel);





 w.show();
    return a.exec(); }
