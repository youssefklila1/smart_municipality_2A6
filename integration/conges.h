#ifndef CONGES_H
#define CONGES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Conges
{
    int matricule,nbrej;
    QString typeconge,dateconge;

public:
    Conges(){}
    Conges(int,int,QString,QString);

    int get_matricule();
    int get_nbrej();
    QString get_dateconge();
    QString get_typeconge();

    bool modifier(int,int,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // CONGES_H
