#include "matmaint.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>



Matmaint::Matmaint(int referance ,QString nom ,QString region,QString date)
{
this->referance=referance;
this->nom=nom;
this->region=region;
this->date=date;

}

QString Matmaint:: get_nom(){return nom;};
QString  Matmaint::get_region(){return region;};
int  Matmaint:: get_referance(){return referance;};
QString Matmaint::get_date(){return date;}


bool Matmaint:: ajouter()
{
QSqlQuery query;
QString ref= QString::number(referance);
query.prepare("INSERT INTO MATERIAUX_MAINT (REFERANCE,NOM,REGION,DATEM) "
                    "VALUES (?,?,?,?)");
query.bindValue(0, ref);
query.bindValue(1, region);
query.bindValue(2, nom);
query.bindValue(3,date);
return    query.exec();
}

bool Matmaint::modifier(int referance ,QString nom ,QString region,QString date)
{
    QSqlQuery query;
    QString ref= QString::number(referance);

    query.prepare("update MATERIAUX_MAINT set REGION=:region,NOM=:nom,DATEM=:date where REFERANCE=:ref");
    query.bindValue(":ref",ref);
    query.bindValue(":nom", nom);
    query.bindValue(":region", region);
    query.bindValue(":date",date);
    return    query.exec();
}






QSqlQueryModel * Matmaint:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_MAINT");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("REGION"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEM"));
 return model;
}

QSqlQueryModel * Matmaint::afficher_rech(QString reff)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from MATERIAUX_MAINT where REFERANCE='"+res+"'");
return model;
}


bool Matmaint::supprimer(int ref)
{
QSqlQuery query;
QString res = QString::number(ref);
query.prepare("Delete from MATERIAUX_MAINT where REFERANCE  = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}

QSqlQueryModel * Matmaint:: afficher_nom()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_POSS");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
 return model;
}

QSqlQueryModel * Matmaint::tri_ref()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATERIAUX_MAINT order by REFERANCE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("REGION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEM"));
    return model;
}

QSqlQueryModel * Matmaint::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select REFERANCE,REGION,NOM,DATEM from MATERIAUX_MAINT order by NOM asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("REGION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEM"));
    return model;
}

