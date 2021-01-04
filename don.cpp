#include "don.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "gestion_employe.h"

Don::Don(int matricule ,int valeur ,QString source ,QString autre ,QString type)
{
    this->matricule=matricule;
    this->type=type;
    this->valeur=valeur;
    this->source=source;
    this->autre=autre;
}
// ajouter
bool Don::ajouter()
   {
   QSqlQuery query;

   QString mat= QString::number(matricule);
   QString val= QString::number(valeur);

//preparation de la requet sql

   query.prepare("INSERT INTO DON ( MATRICULE, SOURCE, TYPE, VALEUR, AUTRE) VALUES (:MATRICULE, :SOURCE,:TYPE,:VALEUR,:AUTRE ) ");

   query.bindValue(":MATRICULE",mat);
   query.bindValue(":SOURCE",source);
   query.bindValue(":TYPE",type);
   query.bindValue(":VALEUR",val);
   query.bindValue(":AUTRE",autre);

//execution de la requet sql
   return    query.exec();
   }
//afficher
QSqlQueryModel * Don::afficher(){
  QSqlQueryModel *model = new QSqlQueryModel;

  //preparation de la requet sql
  model->setQuery("SELECT * FROM DON");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("source"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("valeur"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("autre"));


  return  model;
  }
//supprimer
bool Don::supprimer(int id)
{
QSqlQuery query;
QString idString=QString::number(id);

query.prepare("Delete from DON  where MATRICULE = :id ");
query.bindValue(":id", idString);
return    query.exec();
}
//modifier
bool Don::modifier(int matricule ,int valeur ,QString source ,QString autre ,QString type)
{
    QSqlQuery query;
    QString mt=QString::number(matricule);
    QString vl=QString::number(valeur);

    query.prepare("update DON  set matricule=:matricule,valeur=:valeur,source=:source,type=:type,autre=:autre where matricule=:matricule ");
   query.bindValue(":matricule",mt);
  query.bindValue(":valeur",vl);
  query.bindValue(":source",source);
  query.bindValue(":type",type);
  query.bindValue(":autre",autre);
   return query.exec();
}
//organiser selon matricule
QSqlQueryModel * Don::afficherMatricule(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM DON ORDER BY matricule");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("source"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("valeur"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("autre"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));

  return  model;
  }
//organiser selon type
QSqlQueryModel * Don::afficherType(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM DON ORDER BY type");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("source"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("valeur"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("autre"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));

  return  model;
  }
