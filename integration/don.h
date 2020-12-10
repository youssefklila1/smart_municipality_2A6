#ifndef DON_H
#define DON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Don
{
    int matricule,valeur,id;
    QString source,type,autre;

public:
    Don(){}
    Don(int,int,QString,QString,QString);

    int get_matricule();
    int get_valeur();
    QString get_source();
    QString get_autre();
    QString get_type();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherMatricule();
    QSqlQueryModel * afficherType();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString);
};


#endif // DON_H
