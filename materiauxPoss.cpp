#include "materiauxPoss.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"




Materiauxposs::Materiauxposs(int referance ,QString Nom, QString etat)
{
this->referance=referance;
this->Nom=Nom;
this->etat=etat;
}

int Materiauxposs::get_referance(){return  referance;}
QString Materiauxposs::get_nom(){return  Nom;}
QString Materiauxposs::get_etat(){return  etat;}



bool Materiauxposs::ajouter()
{
QSqlQuery query;
QString ref= QString::number(referance);
query.prepare("INSERT INTO MATERIAUX_POSS (REFERANCE, NOM, ETAT)"
                    "VALUES (?,?,?)");
query.bindValue(0, ref);
query.bindValue(1, Nom);
query.bindValue(2, etat);
return    query.exec();
}


QSqlQueryModel * Materiauxposs:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_POSS");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
 return model;
}


bool Materiauxposs::supprimer(int ref)
{
QSqlQuery query;
QString res = QString::number(ref);
query.prepare("Delete from MATERIAUX_POSS where REFERANCE  = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}



