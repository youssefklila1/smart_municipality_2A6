#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employe{
    int matricule,anneesexp;
    QString nom ,prenom ,email,situationfamiliale,fonction,datenaiss;
public:
    employe(){}
    employe(int,QString,QString,QString,QString,QString,QString,int);

    QString get_nom();
    QString get_prenom();
    int get_matricule();
    QString get_email();
    QString get_datenaiss();
    QString get_situationfamiliale();
    QString get_fonction();
    int get_anneesexp();

    bool modifier(int,QString,QString,QString,QString,QString,QString,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * afficher_rech(QString reff);


    QSqlQueryModel * tri_ref();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * rechercheDynamic(QString);
};

#endif // EMPLOYES_H
