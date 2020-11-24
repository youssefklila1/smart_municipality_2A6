#include "materiauxmanq.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>





Materiauxmanq::Materiauxmanq(int referance ,int prix ,QString nom ,QString dispo)
{
this->referance=referance;
this->prix=prix;
this->nom=nom;
this->dispo=dispo;
}


QString Materiauxmanq:: get_nom(){return nom;};
QString  Materiauxmanq::get_dispo(){return dispo;};
int  Materiauxmanq:: get_referance(){return referance;};
int  Materiauxmanq:: get_prix(){return prix;};

bool Materiauxmanq:: ajouter()
{
QSqlQuery query;
QString ref= QString::number(referance);
QString prx= QString::number(prix);
query.prepare("insert into MATERIAUX_MANQ(referance,prix,nom,dispo) "
                    "values (?,?,?,?)");
query.bindValue(0, ref);
query.bindValue(1, nom);
query.bindValue(2, prix);
query.bindValue(3, dispo);
return    query.exec();
}


QSqlQueryModel * Materiauxmanq:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_MANQ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO"));

 return model;
}

bool Materiauxmanq::supprimer(int ref)
{
QSqlQuery query;
QString res = QString::number(ref);
query.prepare("Delete from MATERIAUX_MANQ where referance = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}
