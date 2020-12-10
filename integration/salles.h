#ifndef SALLES_H
#define SALLES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class salles
{
public:
    salles();
    salles(QString,QString,QString,QString);
    QString get_ref();
    QString get_lieu();
    QString get_date();
    QString get_nom();
    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherCLIENT();
    QSqlQueryModel * trierREF();
    QSqlQueryModel * trierLIEU();
    QSqlQueryModel * trierDATE();
    QSqlQueryModel * rechercheREF(QString);
    QSqlQueryModel * rechercheLIEU(QString);
    QSqlQueryModel * rechercheDATE(QString);
private:
    QString ref,lieu,date,nom;
};

#endif // SALLES_H
