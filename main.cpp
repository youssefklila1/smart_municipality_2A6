#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connetion.h"
#include"dialog.h"
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    Dialog d;
    QFile stylefile(":/image/StyleFile.qss");
    stylefile.open(QFile::ReadOnly);
    QString chaine=QLatin1String(stylefile.readAll());
    a.setStyleSheet(chaine);

    bool test=c.createconnect();
    if(test)
    {d.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
