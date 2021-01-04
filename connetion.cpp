#include "connetion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
    db.setUserName("selim");//inserer nom de l'utilisateur
    db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;
    else throw QString ("Erreur Paramétres"+test);
    return  test;
}

void Connection::fermerConnection()
{db.close();}

/* #include "connetion.h"

Connection::Connection(){}
bool Connection::createconnect(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("selim");
    db.setPassword("esprit20");
    if (db.open()) test=true;
    return test;
}
void Connection::fermerConnection(){
    db.close();
}*/
