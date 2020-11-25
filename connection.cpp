#include "connection.h"
#include<QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("test-bd");
  db.setUserName("EyaB");
  db.setPassword("esprit20");

  if (db.open())
      test=true;

  return test ;

}
