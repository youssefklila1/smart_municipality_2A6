#ifndef CHANTIERS_H
#define CHANTIERS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Chantiers
{
public:
    Chantiers();
    //Societes(QString i,QString n):id(i),nom(n){}
    Chantiers(QString,QString,QString,QString,QString,QString);
    QString get_id();
    QString get_nom();
    QString get_region();
    QString get_rue();
    QString get_affectation();
    QString get_etat();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_chantiers(QString);
    QSqlQueryModel * afficher_societes();

    bool supprimer(QString);
    QSqlQueryModel *trier_c();
    QSqlQueryModel *trier_cr();
    QSqlQueryModel *trier_ce();
private:
    QString id;
    QString nom;
    QString region;
    QString rue;
    QString affectation;
    QString etat;
};


#endif // CHANTIERS_H
