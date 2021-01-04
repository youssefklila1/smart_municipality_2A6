#include "produit.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"



produit::produit()
{

}

produit::produit(const QString &reference, const QString &nom, const QString &quantite, const QString &prix)
        : reference(reference), nom(nom), quantite(quantite), prix(prix) {}
const QString &produit::getreference() const {
    return reference;
}

void produit::setreference(const QString &reference) {
    produit::reference = reference;
}

const QString &produit::getNom() const {
    return nom;
}

void produit::setNom(const QString &nom) {
    produit::nom = nom;
}

const QString &produit::getquantite() const {
    return quantite;
}

void produit::setquantite(const QString &quantite) {
    produit::quantite = quantite;
}

const QString &produit::getprix() const {
    return prix;}
void produit::setprix(const QString &prix) {
    produit::prix = prix;
}
bool produit::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO produit (NOM, REFERENCE, QUANTITE, PRIX) "
                      "VALUES (?, ?, ?, ?)");
        query.bindValue(0, this->nom);
        query.bindValue(1, this->reference);
        query.bindValue(2, this->quantite);
        query.bindValue(3, this->prix);
        return query.exec();
}
bool produit::modifier(QString nom,QString reference ,QString quantite,QString prix)
{
    QSqlQuery query;

    query.prepare("update produit set NOM=:nom,PRIX=:prix,QUANTITE=:quantite where REFERENCE=:reference");
    query.bindValue(":reference",reference);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    return    query.exec();
}
QSqlQueryModel *produit::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produit");


    return model;

}
bool produit::delet()

{
QSqlQuery query;
    query.prepare("delete from produit where reference=:todelete");
            query.bindValue(":todelete",reference);
            return query.exec();

}
QSqlQueryModel *produit::tri2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produit order by PRIX ");


    return model;

}
