#include "mainwindow.h"
#include "globales.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(database.isOpen()){

            QMessageBox::information(0, "Base de données connectée !", " Procéder au programme");
    MainWindow w ;
    w.show();
            return a.exec();
        }else {
            QMessageBox::critical(0, "Erreur de connexion!", "Base de données non connectée !");
            return a.exec();
        }
    MainWindow w;
    w.show();
    return a.exec();
}
