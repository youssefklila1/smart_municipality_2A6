#include "chantiers.h"
#include "societes.h"
Chantiers::Chantiers()
{
id="";
nom="";
region="";
rue="";
affectation="";
etat="";
}
Chantiers::Chantiers(QString id,QString nom,QString region,QString rue,QString affectation,QString etat)
{
    this ->id=id;
    this ->nom=nom;
    this ->region=region;
    this ->rue=rue;
    this ->affectation=affectation;
    this ->etat=etat;
}
QString Chantiers::get_id(){return id;}
QString Chantiers::get_nom(){return nom;}
QString Chantiers::get_region(){return region;}
QString Chantiers::get_rue(){return rue;}
QString Chantiers::get_affectation(){return affectation;}
QString Chantiers::get_etat(){return etat;}

bool Chantiers::ajouter(){
    QSqlQuery query;
        query.prepare("INSERT INTO CHANTIERS(ID, NOM, REGIONS, RUE, AFFECTATION, ETAT) VALUES (:ID, :NOM, :REGIONS, :RUE, :AFFECTATION, :ETAT)");
        query.bindValue(":ID", id);
        query.bindValue(":NOM", nom);
        query.bindValue(":REGIONS", region);
        query.bindValue(":RUE", rue);
        query.bindValue(":AFFECTATION", affectation);
        query.bindValue(":ETAT", etat);

        return query.exec();
}

bool Chantiers::supprimer(QString idchantiers){
    QSqlQuery qry;
        qry.prepare("Delete from CHANTIERS where ID = :ID");
        qry.bindValue(":ID",idchantiers);
        return qry.exec();
}
QSqlQueryModel * Chantiers::afficher(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM CHANTIERS");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("REGIONS"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("RUE"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("AFFECTATION"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
        return model;

}



QSqlQueryModel * Chantiers::afficher_societes(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM SOCIETES");

        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        return model;

}
QSqlQueryModel * Chantiers::afficher_chantiers(QString nom)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CHANTIERS WHERE NOM  = '"+ nom +"' ");
    query.bindValue(":NOM", nom);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    model->setHeaderData(2,Qt::Horizontal,"REGIONS");
    model->setHeaderData(3,Qt::Horizontal,"RUE");
    model->setHeaderData(4,Qt::Horizontal,"AFFECTATION");
    model->setHeaderData(5,Qt::Horizontal,"ETAT");
    return model ;


}

QSqlQueryModel *Chantiers::trier_c()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from CHANTIERS ORDER BY NOM");

        model->setHeaderData(0,Qt::Horizontal,"ID");
        model->setHeaderData(1,Qt::Horizontal,"NOM");
        model->setHeaderData(2,Qt::Horizontal,"REGIONS");
        model->setHeaderData(3,Qt::Horizontal,"RUE");
        model->setHeaderData(4,Qt::Horizontal,"AFFECTATION");
        model->setHeaderData(5,Qt::Horizontal,"ETAT");
        return model ;
}

QSqlQueryModel *Chantiers::trier_cr()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from CHANTIERS ORDER BY REGIONS");

        model->setHeaderData(0,Qt::Horizontal,"ID");
        model->setHeaderData(1,Qt::Horizontal,"NOM");
        model->setHeaderData(2,Qt::Horizontal,"REGIONS");
        model->setHeaderData(3,Qt::Horizontal,"RUE");
        model->setHeaderData(4,Qt::Horizontal,"AFFECTATION");
        model->setHeaderData(5,Qt::Horizontal,"ETAT");
        return model ;
}
QSqlQueryModel *Chantiers::trier_ce()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from CHANTIERS ORDER BY ETAT");

        model->setHeaderData(0,Qt::Horizontal,"ID");
        model->setHeaderData(1,Qt::Horizontal,"NOM");
        model->setHeaderData(2,Qt::Horizontal,"REGIONS");
        model->setHeaderData(3,Qt::Horizontal,"RUE");
        model->setHeaderData(4,Qt::Horizontal,"AFFECTATION");
        model->setHeaderData(5,Qt::Horizontal,"ETAT");
        return model ;
}
