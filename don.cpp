#include "don.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"

Don::Don(int matricule ,int valeur ,QString source ,QString autre ,QString type)
{
    this->matricule=matricule;
    this->type=type;
    this->valeur=valeur;
    this->source=source;
    this->autre=autre;
}

bool Don::ajouter()
   {
   QSqlQuery query;
   QString mat= QString::number(matricule);
   QString val= QString::number(valeur);

  /* query.prepare("INSERT INTO DON (ID,MATRICULE,SOURCE,TYPE,VALEUR,AUTRE)"
                       "VALUES (:MATRICULE,:MATRICULE,:SOURCE,:TYPE,:VALEUR,:AUTRE)");*/

   query.prepare("INSERT INTO MYRIAM.DON (ID, MATRICULE, SOURCE, TYPE, VALEUR, AUTRE) VALUES (:MATRICULE,:MATRICULE, :SOURCE,:TYPE,:VALEUR,:AUTRE )");

   query.bindValue(":MATRICULE",mat);
   query.bindValue(":SOURCE",source);
   query.bindValue(":TYPE",type);
   query.bindValue(":VALEUR",val);
   query.bindValue(":AUTRE",autre);

   return    query.exec();
   }

QSqlQueryModel * Don::afficher(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM MYRIAM.DON");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("source"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("valeur"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("autre"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));

  return  model;
  }
bool Don::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);

query.prepare("Delete from MYRIAM.DON  where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Don::modifier(int matricule ,int valeur ,QString source ,QString autre ,QString type){
    QSqlQuery query;
    QString mt=QString::number(matricule);
    QString vl=QString::number(valeur);

    query.prepare("update MYRIAM.DON  set matricule=:matricule,valeur=:valeur,source=:source,type=:type,autre=:autre where matricule=:matricule ");
   query.bindValue(":matricule",mt);
  query.bindValue(":valeur",vl);
  query.bindValue(":source",source);
  query.bindValue(":type",type);
  query.bindValue(":autre",autre);
   return query.exec();
}
