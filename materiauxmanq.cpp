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
query.prepare("insert into MATERIAUX_MANQ(referance,nom,prix,dispo) "
                    "values (?,?,?,?)");
query.bindValue(0, ref);
query.bindValue(1, nom);
query.bindValue(2, prix);
query.bindValue(3, dispo);
return    query.exec();
}


bool Materiauxmanq::modifier(int referance ,int prix ,QString nom ,QString dispo)
{
    QSqlQuery query;
    QString ref= QString::number(referance);
    QString prx= QString::number(prix);

    query.prepare("update MATERIAUX_MANQ set PRIX=:prix,NOM=:nom,DISPO=:dispo where REFERANCE=:ref");
    query.bindValue(":ref",ref);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prx);
    query.bindValue(":dispo",dispo);
    return    query.exec();
}

QSqlQueryModel * Materiauxmanq:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_MANQ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO"));

 return model;
}


QSqlQueryModel * Materiauxmanq::afficher_rech(QString reff)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from MATERIAUX_MANQ where REFERANCE='"+res+"'");
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

QSqlQueryModel * Materiauxmanq::tri_ref()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATERIAUX_MANQ order by REFERANCE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO"));
    return model;
}

QSqlQueryModel * Materiauxmanq::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select REFERANCE,NOM,PRIX,DISPO from MATERIAUX_MANQ order by NOM asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO"));
    return model;
}
