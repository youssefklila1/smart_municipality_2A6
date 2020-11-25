#include "connection.h"
#include<QDebug>
//test tutoriel
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_CPP");
db.setUserName("mariem");//inserer nom de l'utilisateur
db.setPassword("esprit");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

else

{return  test;
    qDebug()<<"this is my error :"<<db.lastError();
}
}
