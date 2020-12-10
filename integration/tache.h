#ifndef TACHE_H
#define TACHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class tache
{
    int matricule,identifiant;
    QString libelle,debut,fin;
public:
    tache(){}
    tache(int,int,QString,QString,QString);

    int get_matricule();
    int get_identifiant();
    QString get_debut();
    QString get_fin();
    QString get_libelle();

    bool modifier(int,int,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_id();
    bool supprimer(int);

    QSqlQueryModel * rechercheDynamic(QString);
    QSqlQueryModel * afficher_rech(QString reff);

};

#endif // TACHE_H
