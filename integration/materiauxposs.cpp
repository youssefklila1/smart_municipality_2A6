#include "materiauxposs.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "gestion_materiaux.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QMessageBox>
#include <QComboBox>
#include <QPixmap>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
QT_CHARTS_USE_NAMESPACE


Materiauxposs::Materiauxposs(int referance ,QString Nom, QString etat)
{
this->referance=referance;
this->Nom=Nom;
this->etat=etat;
}

int Materiauxposs::get_referance(){return  referance;}
QString Materiauxposs::get_nom(){return  Nom;}
QString Materiauxposs::get_etat(){return  etat;}

bool Materiauxposs::ajouter()
{
QSqlQuery query;
QString ref= QString::number(referance);
query.prepare("INSERT INTO MATERIAUX_POSS (REFERANCE, NOM, ETAT)"
                    "VALUES (?,?,?)");
query.bindValue(0, ref);
query.bindValue(1, Nom);
query.bindValue(2, etat);
return    query.exec();
}

bool Materiauxposs::modifier(int referance,QString nom ,QString etat)
{
    QSqlQuery query;
    QString ref= QString::number(referance);
    query.prepare("update MATERIAUX_POSS set NOM=:nom,ETAT=:etat where REFERANCE=:ref");
    query.bindValue(":ref",ref);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);
    return    query.exec();
}


QSqlQueryModel * Materiauxposs:: afficher()
{
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from MATERIAUX_POSS");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
 return model;
}

QSqlQueryModel * Materiauxposs:: afficher_nom()
{
  QSqlQuery query;
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select NOM from MATERIAUX_POSS ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
 return model;
}

QSqlQueryModel * Materiauxposs::afficher_rech(QString reff)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= reff;
 model->setQuery("select * from MATERIAUX_POSS where REFERANCE='"+res+"'");
return model;
}

bool Materiauxposs::supprimer(int ref)
{
QSqlQuery query;
QString res = QString::number(ref);
query.prepare("Delete from MATERIAUX_POSS where REFERANCE  = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}

QSqlQueryModel * Materiauxposs::tri_ref()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATERIAUX_POSS order by REFERANCE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel * Materiauxposs::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select REFERANCE,NOM,ETAT from MATERIAUX_POSS order by NOM asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel * Materiauxposs::rechercheDynamic(QString SearchName)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from MATERIAUX_POSS where NOM LIKE '"+SearchName+"%'OR ETAT like '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERANCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));

    return  model;
}


bool  Materiauxposs::verif_nom(QString nom)
{
    bool test=true;
    int i;
    if(nom.length()>20)
    {
       test=false;
       return  test;
    }
    else
    {
        for(i=0;i<nom.length();i++)
        {
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z'))))
            {
                test=false;
                return  test;

            }
        }
    }
    return  test;
}

void Materiauxposs::imprimer()
{
    QPdfWriter pdf("C:/Users/asus/Desktop/imprimer/Pdf.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Playbill", 30));
        painter.drawText(1100,1200,"Liste des materiaux  ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));

        painter.drawText(200,3300,"REFERANCE");
        painter.drawText(1700,3300,"NOM");
        painter.drawText(3200,3300,"ETAT");

        QSqlQuery query;
        query.prepare("select * from MATERIAUX_POSS");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
           i = i + 500;
        }

                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/asus/Desktop/imprimer/Pdf.pdf"));
                painter.end();


}
