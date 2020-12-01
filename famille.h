#ifndef FAMILLE_H
#define FAMILLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class famille
{
    int matricule,don,id,nbr_membres;
    QString nom,besoin,region;

public:
    //constuctors
    famille(){};
    famille(int,int,int,QString,QString,QString);
    // crud methodes

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherNBR();
    QSqlQueryModel * afficherBesoin();
    bool supprimer(int);
    bool modifier(int,int,int,QString,QString,QString);
};

#endif // FAMILLE_H
