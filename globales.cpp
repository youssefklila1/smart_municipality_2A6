#include "globales.h"

// DATABSAE ::

QSqlDatabase connect_to_database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Karim");
    db.setPassword("esprit2020");
    db.open();
    return db;
}

QSqlDatabase database = connect_to_database();
