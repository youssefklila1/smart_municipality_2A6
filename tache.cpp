#include "tache.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"

tache::tache(int matricule ,int identifiant ,int debut ,int fin,QString libelle)
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
QString db= QString::number(debut);
QString fi= QString::number(fin);

query.prepare("INSERT INTO TACHE (MATRICULE,IDENTIFIANT,DEBUT,FIN,LIBELLE )"
                    "VALUES (?,?,?,?,?)");
query.bindValue(0, mat3);
query.bindValue(1, id);
query.bindValue(2, db);
query.bindValue(3, fi);
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

bool tache::supprimer(int mat3)
{
QSqlQuery query;
QString res = QString::number(mat3);
query.prepare("Delete from TACHE where MATRICULE = :mat3 ");
query.bindValue(":mat3", res);
return    query.exec();
}
