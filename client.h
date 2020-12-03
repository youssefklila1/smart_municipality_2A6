#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_cin();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * trierCIN();
    QSqlQueryModel * trierNOM();
    QSqlQueryModel * trierDATE();
    QSqlQueryModel * rechercheNOM(QString);
    QSqlQueryModel * recherchePRENOM(QString);
    QSqlQueryModel * rechercheCIN(QString);


    bool supprimer(QString);
    bool modifier(QString);
private:
    QString nom,prenom;
    QString cin,date;
};

#endif // CLIENT_H
