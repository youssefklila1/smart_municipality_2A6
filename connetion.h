#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
private:
        QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void fermerConnection();
};

#endif // CONNECTION_H
