#include "client.h"
#include <QDebug>
#include <iostream>
#include <QString>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
Client::Client()
{
nom="";
prenom="";
cin="";
date="";
}
Client::Client(QString nom,QString prenom,QString cin,QString date)
{
  this->date=date;
  this->nom=nom;
  this->prenom=prenom;
  this->cin=cin;

}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_cin(){return  cin;}
QString Client::get_date(){return date;}

bool Client::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO client (NOM, PRENOM,CIN, DATEM) "
                    "VALUES (:nom, :prenom, :cin, :date)");
query.bindValue(":date", date);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":cin", cin);


return    query.exec();
}
QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));


    return model;
}

bool Client::supprimer(QString cin)
{
QSqlQuery query;
 query.prepare("Delete from client where cin = :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * Client::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
        model->setQuery("select CIN from client") ;


    return model;

}
bool Client::modifier(QString cin)
{
    QSqlQuery query ;


        query.prepare("Update client set NOM=:NOM,PRENOM=:PRENOM,CIN=:CIN,DATEM=:DATEM where CIN=:CIN");
        query.bindValue(":NOM", this->nom);
        query.bindValue(":PRENOM", this->prenom);
        query.bindValue(":CIN", this->cin );
        query.bindValue(":DATEM", this->date);
        return query.exec();



        return query.exec();
}
QSqlQueryModel * Client::trierNOM ()
{


    //trier par nom
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from client order by NOM ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return model;

}
QSqlQueryModel * Client::trierCIN ()
{



    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from client order by CIN DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return model;



}
QSqlQueryModel * Client::trierDATE ()
{



    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from client order by DATEM DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));


    return model;



}
QSqlQueryModel * Client::rechercheNOM(QString nom)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = nom;

    query.prepare("select * from client where NOM=:NOM");
    query.bindValue(":NOM", nom);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
       return model;

}
QSqlQueryModel * Client::recherchePRENOM(QString prenom)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = prenom;

    query.prepare("select * from client where PRENOM=:PRENOM");
    query.bindValue(":PRENOM", prenom);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
       return model;

}
QSqlQueryModel * Client::rechercheCIN(QString cin)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = cin;

    query.prepare("select * from client where CIN=:CIN");
    query.bindValue(":CIN", cin);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
       return model;

}


