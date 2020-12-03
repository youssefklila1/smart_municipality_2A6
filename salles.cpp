#include "salles.h"

salles::salles()
{
    ref="";
    lieu="";
    date="";
    nom="";
}
salles::salles(QString ref,QString lieu,QString date,QString nom)
{
  this->ref=ref;
  this->lieu=lieu;
  this->date=date;
  this->nom=nom;

}
QString salles::get_ref(){return  ref;}
QString salles::get_lieu(){return lieu;}
QString salles::get_date(){return  date;}
QString salles::get_nom(){return nom;}

bool salles::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO salles (REF, LIEU,DATES,NOM) "
                    "VALUES (:ref, :lieu, :date, :nom)");
query.bindValue(":ref", ref);
query.bindValue(":lieu", lieu);
query.bindValue(":date", date);
query.bindValue(":nom", nom);


return    query.exec();
}
QSqlQueryModel * salles::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SALLES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Referance "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Lieu"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
bool salles::supprimer(QString ref)
{
QSqlQuery query;
 query.prepare("Delete from salles where ref = :ref ");
query.bindValue(":ref", ref);
return    query.exec();
}
bool salles::modifier(QString ref)
{
    QSqlQuery query ;



        query.prepare("Update SALLES set REF=:REF,LIEU=:LIEU,DATES=:DATES where REF=:REF");
        query.bindValue(":REF", this->ref);
        query.bindValue(":LIEU", this->lieu);
        query.bindValue(":DATES", this->date );
        return query.exec();



        return query.exec();
}
QSqlQueryModel * salles::trierLIEU ()
{


    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from salles order by LIEU ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));



    return model;

}
QSqlQueryModel * salles::trierREF ()
{


    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from salles order by REF DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));



    return model;



}
QSqlQueryModel * salles::trierDATE ()
{


    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from salles order by DATES DESC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));



    return model;



}
QSqlQueryModel * salles::rechercheREF(QString ref)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = ref;

    query.prepare("select * from salles where REF=:REF");
    query.bindValue(":REF", ref);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
       return model;

}
QSqlQueryModel * salles::rechercheLIEU(QString lieu)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = lieu;

    query.prepare("select * from salles where LIEU=:LIEU");
    query.bindValue(":LIEU", lieu);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
       return model;

}
QSqlQueryModel * salles::rechercheDATE(QString date)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res = date;

    query.prepare("select * from salles where DATES=:DATES");
    query.bindValue(":DATES", date);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Referance"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Lieu"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
       return model;

}
QSqlQueryModel * salles::afficherCLIENT()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
        model->setQuery("select NOM from client") ;


    return model;

}
