#ifndef TACHE_H
#define TACHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class tache
{
    int matricule,identifiant,debut,fin;
    QString libelle;
public:
    tache(){}
    tache(int,int,int,int,QString);

    int get_matricule();
    int get_identifiant();
    int get_debut();
    int get_fin();
    QString get_libelle();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // TACHE_H
