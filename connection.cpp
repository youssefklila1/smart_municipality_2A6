#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("connect");
  db.setUserName("asus");
  db.setPassword("asus");

  if (db.open())
      test=true;

   return test ;
}


void Connection::closeconnection() {db.close();}
