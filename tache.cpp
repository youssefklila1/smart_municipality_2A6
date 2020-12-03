#include "tache.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"

tache::tache(int matricule ,int identifiant ,QString debut ,QString fin,QString libelle)
{
this->matricule=matricule;
this->identifiant=identifiant;
this->debut=debut;
this->fin=fin;
this->libelle=libelle;
}

bool tache::ajouter()
{
QSqlQuery query;
QString mat3= QString::number(matricule);
QString id= QString::number(identifiant);


query.prepare("INSERT INTO TACHE (MATRICULE,IDENTIFIANT,DEBUT,FIN,LIBELLE )"
                    "VALUES (?,?,?,?,?)");
query.bindValue(0, mat3);
query.bindValue(1, id);
query.bindValue(2, debut);
query.bindValue(3, fin);
query.bindValue(4, libelle);

return    query.exec();
}
QSqlQueryModel * tache:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from TACHE ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEBUT"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("FIN"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIBELLE"));
  return model;
 }

QSqlQueryModel * tache:: afficher_id(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select IDENTIFIANT from TACHE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
     return model;
    }

bool tache::supprimer(int id)
{
QSqlQuery query;
QString res = QString::number(id);
query.prepare("Delete from TACHE where IDENTIFIANT = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool tache::modifier(int matricule ,int identifiant ,QString debut ,QString fin,QString libelle)
{

    QSqlQuery query;
    QString mat3= QString::number(matricule);
    QString id= QString::number(identifiant);


    query.prepare("update TACHE set IDENTIFIANT=:id,DEBUT=:debut,FIN=:fin,LIBELLE=:libelle where MATRICULE=:mat3");
    query.bindValue(":mat3",mat3);
    query.bindValue(":id",id);
    query.bindValue(":debut",debut);
    query.bindValue(":fin",fin);
    query.bindValue(":libelle",libelle);


    return    query.exec();
}


QSqlQueryModel * tache::rechercheDynamic(QString SearchName)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from TACHE where LIBELLE LIKE '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEBUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIBELLE"));

    return  model;
}

QSqlQueryModel * tache::afficher_rech(QString reff)//recherche selon matricule
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from TACHE where MATRICULE='"+res+"'");
return model;
}



