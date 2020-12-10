#ifndef SOCIETES_H
#define SOCIETES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Societes
{
public:
    Societes();
    //Societes(QString i,QString n):id(i),nom(n){}
    Societes(QString,QString);
    QString get_id();
    QString get_nom();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_societes(QString);
    bool supprimer(QString);
    QSqlQueryModel *trier();
    QSqlQueryModel *trier_i();
private:
    QString id;
    QString nom;
};

#endif // SOCIETES_H
