#include "don.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dialog.h"

Don::Don(int matricule ,int type_don ,int valeur ,QString source,QString autre)
{
    this->matricule=matricule;
    this->type_don=type_don;
    this->valeur=valeur;
    this->source=source;
    this->autre=autre;
}

bool Don::ajouter()
   {
   QSqlQuery query;
   QString mat= QString::number(matricule);
   QString type= QString::number(type_don);
   QString val= QString::number(valeur);

   query.prepare("INSERT INTO CONGE (MATRICULE, NBREJ, DATECONGE, TYPECONGE )"
                       "VALUES (?,?,?,?)");
   query.bindValue(0, mat);
   query.bindValue(1, type);
   query.bindValue(2, val);
   query.bindValue(3, source);
   query.bindValue(4, autre);

   return    query.exec();
   }
