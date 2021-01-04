#include "societes.h"

Societes::Societes()
{
id="";
nom="";
}
Societes::Societes(QString id,QString nom)
{
    this ->id=id;
    this ->nom=nom;
}
QString Societes::get_id(){return id;}
QString Societes::get_nom(){return nom;}

bool Societes::ajouter(){
    QSqlQuery query;
        query.prepare("INSERT INTO SOCIETES(ID, NOM) VALUES (:ID, :NOM)");
        query.bindValue(":ID", id);
        query.bindValue(":NOM", nom);
        return query.exec();
}

bool Societes::supprimer(QString idsocietes){
    QSqlQuery qry;
        qry.prepare("Delete from SOCIETES where ID = :ID");
        qry.bindValue(":ID",idsocietes);
        return qry.exec();
}
   QSqlQueryModel * Societes::afficher(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM SOCIETES");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        return model;
}

QSqlQueryModel *Societes::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from SOCIETES ORDER BY NOM");

        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"ID");
        return model ;
}

QSqlQueryModel * Societes::afficher_societes(QString nom)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from SOCIETES WHERE NOM  LIKE '"+ nom +"%' ");
    query.bindValue(":NOM", nom);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    return model ;


}
QSqlQueryModel *Societes::trier_i()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from SOCIETES ORDER BY ID");

        model->setHeaderData(0,Qt::Horizontal,"NOM");
        model->setHeaderData(1,Qt::Horizontal,"ID");
        return model ;
}
