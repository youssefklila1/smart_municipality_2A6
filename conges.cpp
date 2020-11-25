#include "conges.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"


    Conges::Conges(int matricule ,int nbrej ,QString dateconge ,QString typeconge)
    {
    this->matricule=matricule;
    this->nbrej=nbrej;
    this->dateconge=dateconge;
    this->typeconge=typeconge;

    }

    bool Conges::ajouter()
    {
    QSqlQuery query;
    QString mat2= QString::number(matricule);
    QString nb= QString::number(nbrej);


    query.prepare("INSERT INTO CONGE (MATRICULE, NBREJ, DATECONGE, TYPECONGE )"
                        "VALUES (?,?,?,?)");
    query.bindValue(0, mat2);
    query.bindValue(1, nb);
    query.bindValue(2, dateconge);
    query.bindValue(3, typeconge);

    return    query.exec();
    }

    QSqlQueryModel * Conges:: afficher()
    {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from CONGE ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBREJ"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATECONGE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPECONGE"));

     return model;
    }

    bool Conges::supprimer(int mat2)
    {
    QSqlQuery query;
    QString res = QString::number(mat2);
    query.prepare("Delete from CONGE where MATRICULE = :mat2 ");
    query.bindValue(":mat2", res);
    return    query.exec();
    }
