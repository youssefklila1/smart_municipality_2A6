#include "famille.h"
/*    int matricule,don,id,nbr_membres;
    QString nom,besoin,region;*/

famille::famille(int matricule ,int nbr_membres,int don ,QString nom ,QString besoin ,QString region)
{
    this->matricule=matricule;
    this->don=don;
    this->nbr_membres=nbr_membres;
    this->nom=nom;
    this->besoin=besoin;
    this->region=region;
}

bool famille::ajouter()
   {
   QSqlQuery query;
   QString mat= QString::number(matricule);
   QString nbr= QString::number(nbr_membres);
   QString dn= QString::number(don);


   //query.prepare("INSERT INTO MYRIAM.FAMILLES (ID, MATRICULE, BESOIN, NBR_MEMBRES, REGION, DON,NOM) VALUES (:MATRICULE, :MATRICULE,:BESOIN, :NBR_MEMBRES, :REGION,:DON,:NOM)");

query.prepare("INSERT INTO MYRIAM.FAMILLES (ID, MATRICULE, NOM, BESOIN, NBR_MEMBRES, REGION, DON) VALUES (:MATRICULE, :MATRICULE,:NOM,:BESOIN,'1',  :REGION,:DON)");
   query.bindValue(":MATRICULE",mat);
   query.bindValue(":NBR_MEMEBERS",nbr);
   query.bindValue(":BESOIN",besoin);
   query.bindValue(":REGION",region);
   query.bindValue(":DON",dn);
   query.bindValue(":NOM",nom);


   return    query.exec();
   }

QSqlQueryModel * famille::afficher(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM MYRIAM.FAMILLES ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("besoin"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_memebres"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("don"));

  return  model;
  }

bool famille::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);

query.prepare("Delete from MYRIAM.familles  where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool famille::modifier(int matricule ,int nbr_membres,int don ,QString nom ,QString besoin ,QString region){
    QSqlQuery query;
    QString mat= QString::number(matricule);
    QString nbr= QString::number(nbr_membres);
    QString dn= QString::number(don);

    query.prepare("update MYRIAM.FAMILLES set matricule=:matricule,NBR_MEMBRES=:NBR_MEMBRES,BESOIN=:BESOIN,REGION=:REGION,DON=:DON,NOM=:NOM,id=:matricule where matricule=:matricule ");
    query.bindValue(":matricule",mat);
    query.bindValue(":NBR_MEMBRES",nbr);
    query.bindValue(":BESOIN",besoin);
    query.bindValue(":REGION",region);
    query.bindValue(":DON",dn);
    query.bindValue(":NOM",nom);
   return query.exec();
}


//affichage trie famille
QSqlQueryModel * famille::afficherBesoin(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM MYRIAM.FAMILLES  ORDER BY BESOIN ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("besoin"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_memebres"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("don"));

  return  model;
  }

QSqlQueryModel * famille::afficherNBR(){
  QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM MYRIAM.FAMILLES ORDER BY NBR_MEMBRES");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("besoin"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_memebres"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("don"));

  return  model;
  }

QSqlQueryModel * famille::rechercheDynamic(QString SearchName){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM MYRIAM.FAMILLES WHERE nom LIKE '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("besoin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbr_memebres"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("don"));

    return  model;
}
