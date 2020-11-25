#ifndef DON_H
#define DON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Don
{
    int matricule,type_don,valeur;
    QString source,autre;

public:
    Don(){}
    Don(int,int,int,QString,QString);

    int get_matricule();
    int get_type_don();
    int get_valeur();
    QString get_source();
    QString get_autre();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};


#endif // DON_H
