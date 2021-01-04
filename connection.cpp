#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("asus2");
  db.setUserName("asus2");
  db.setPassword("asus2");

  if (db.open())
      test=true;

   return test ;
}


void Connection::closeconnection() {db.close();}
