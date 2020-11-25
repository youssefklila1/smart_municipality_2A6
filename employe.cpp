#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"

employe::employe(int matricule ,QString nom ,QString prenom ,QString email,QString situationfamiliale, QString fonction, int datenaiss, int anneesexp)
{
this->matricule=matricule;
this->nom=nom;
this->prenom=prenom;
this->email=email;
this->situationfamiliale=situationfamiliale;
this->fonction=fonction;
this->datenaiss=datenaiss;
this->anneesexp=anneesexp;
}

bool employe::ajouter()
{
QSqlQuery query;
QString mat= QString::number(matricule);
QString anees= QString::number(anneesexp);

query.prepare("INSERT INTO EMPLOYE (MATRICULE, NOM, PRENOM, EMAIL, SITUATIONFAMILIALE, FONCTION, DATENAISS, ANNEESEXP )"
                    "VALUES (?,?,?,?,?,?,?,?)");
query.bindValue(0, mat);
query.bindValue(1, nom);
query.bindValue(2, prenom);
query.bindValue(3, email);
query.bindValue(4, situationfamiliale);
query.bindValue(5, fonction);
query.bindValue(6, datenaiss);
query.bindValue(7, anees);
return    query.exec();
}

bool employe::modifier(int matricule ,QString nom ,QString prenom ,QString email,QString situationfamiliale, QString fonction, int datenaiss, int anneesexp)
{

    QSqlQuery query;
    QString mat= QString::number(matricule);
    QString anees= QString::number(anneesexp);
    QString date= QString::number(datenaiss);

    query.prepare("update EMPLOYE set NOM=:nom,PRENOM=:prenom,EMAIL=:email,SITUATIONFAMILIALE=:situationfamiliale,FONCTION=:fonction,DATENAISS=:date,ANNEESEXP=:anees where MATRICULE=:mat");
    query.bindValue(":mat",mat);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":situationfamiliale",situationfamiliale);
    query.bindValue(":fonction",fonction);
    query.bindValue(":date",date);
    query.bindValue(":anees",anees);
    return    query.exec();
}








QSqlQueryModel * employe:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from EMPLOYE ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("SITUATIONFAMILIALE"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("FONCTION"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATENAISS"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("ANNEESEXP"));
 return model;
}

bool employe::supprimer(int mat)
{

    QSqlQuery query;
QString res = QString::number(mat);
query.prepare("Delete from EMPLOYE where MATRICULE = :mat ");
query.bindValue(":mat", res);
return    query.exec();
}

QSqlQueryModel * employe::afficher_rech(QString reff)//recherche selon matricule
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from EMPLOYE where MATRICULE='"+res+"'");
return model;
}


QSqlQueryModel * employe::tri_ref()//tri decroissant
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYE order by MATRICULE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("SITUATIONFAMILIALE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("FONCTION"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATENAISS"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("ANNEESEXP"));
    return model;
}







