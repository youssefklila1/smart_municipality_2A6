#include "materiauxPoss.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"
#include <QComboBox>

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

bool Materiauxposs::modifier(int referance,QString nom ,QString etat)
{
    QSqlQuery query;
    QString ref= QString::number(referance);
    query.prepare("update MATERIAUX_POSS set NOM=:nom,ETAT=:etat where REFERANCE=:ref");
    query.bindValue(":ref",ref);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);
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

QSqlQueryModel * Materiauxposs:: afficher_nom()
{
  QSqlQuery query;
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select NOM from MATERIAUX_POSS ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
 return model;
}

QSqlQueryModel * Materiauxposs::afficher_rech(QString reff)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from MATERIAUX_POSS where REFERANCE='"+res+"'");
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

QSqlQueryModel * Materiauxposs::tri_ref()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATERIAUX_POSS order by REFERANCE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel * Materiauxposs::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select REFERANCE,NOM,ETAT from MATERIAUX_POSS order by NOM asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel * Materiauxposs::rechercheDynamic(QString SearchName)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from MATERIAUX_POSS where NOM LIKE '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));

    return  model;
}





