#ifndef MATERIAUXPOSS_H
#define MATERIAUXPOSS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiauxposs
{

    QString Nom,etat;
    int referance ;


public:
    Materiauxposs(){};
    Materiauxposs(int,QString,QString);

    QString get_nom();
    QString get_etat();
    int get_referance();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

};

#endif // MATERIAUXPOSS_H
