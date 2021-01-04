#include "fournisseurs.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"



Fournisseurs::Fournisseurs()
{

}

Fournisseurs::Fournisseurs(const QString &matricule, const QString &nom, const QString &adresse, const QString &tel)
        : matricule(matricule), nom(nom), adresse(adresse), tel(tel) {}
const QString &Fournisseurs::getMatricule() const {
    return matricule;
}

void Fournisseurs::setMatricule(const QString &matricule) {
    Fournisseurs::matricule = matricule;
}

const QString &Fournisseurs::getNom() const {
    return nom;
}

void Fournisseurs::setNom(const QString &nom) {
    Fournisseurs::nom = nom;
}

const QString &Fournisseurs::getAdresse() const {
    return adresse;
}

void Fournisseurs::setAdresse(const QString &adresse) {
    Fournisseurs::adresse = adresse;
}

const QString &Fournisseurs::getTel() const {
    return tel;}
void Fournisseurs::setTel(const QString &tel) {
    Fournisseurs::tel = tel;
}
bool Fournisseurs::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO fournisseurs ( MATRICULE, NOM,TELEPHONE, ADRESSE) "
                      "VALUES (?, ?, ?, ?)");
        query.bindValue(0, this->matricule);
        query.bindValue(1, this->nom);
        query.bindValue(2, this->tel);
        query.bindValue(3, this->adresse);
        return query.exec();
}

bool Fournisseurs::modifier(QString matricule,QString nom ,QString tel,QString adresse)
{
    QSqlQuery query;

    query.prepare("update Fournisseurs set NOM=:nom,TELEPHONE=:tel,ADRESSE=:adresse  where MATRICULE=:matricule");
    query.bindValue(":matricule",matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":adresse", adresse);
    return    query.exec();
}
QSqlQueryModel *Fournisseurs::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Fournisseurs");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}
bool Fournisseurs::delet()

{
QSqlQuery query;
    query.prepare("delete from Fournisseurs where matricule=:todelete");
            query.bindValue(":todelete",matricule);
            return query.exec();

}
QSqlQueryModel *Fournisseurs::tri1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Fournisseurs order by NOM ");


    return model;

}

