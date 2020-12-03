#ifndef MATMAINT_H
#define MATMAINT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Matmaint
{
int referance;
QString nom,region,date;

public:
    Matmaint(){};
    Matmaint(int,QString,QString,QString);

    QString get_nom();
    QString get_region();
    int get_referance();
    QString get_date();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_rech(QString reff);
    QSqlQueryModel * tri_ref();
    QSqlQueryModel * tri_nom();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString);
    QSqlQueryModel * afficher_nom();
    QSqlQueryModel * rechercheDynamic(QString);

};

#endif // MATMAINT_H
