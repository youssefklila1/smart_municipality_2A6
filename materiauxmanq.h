#ifndef MATERIAUXMAINT_H
#define MATERIAUXMAINT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiauxmanq
{
  int referance,prix;
   QString nom,dispo;



public:
    Materiauxmanq(){};
    Materiauxmanq(int,int,QString,QString);

    QString get_nom();
    QString get_dispo();
    int get_referance();
    int get_prix();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

};

#endif // MATERIAUXMAINT_H



