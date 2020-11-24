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
    bool supprimer(int);

};

#endif // MATMAINT_H
