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
    bool supprimer(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * tri_ref();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_rech(QString reff);
    QSqlQueryModel * afficher_nom();
    QSqlQueryModel * rechercheDynamic(QString);
    bool verif_nom(QString);
    void imprimer();

    bool verif_id(int);




};

#endif // MATERIAUXPOSS_H
