#ifndef __DATABASECONNECTION_H__
#define __DATABASECONNECTION_H__

#include <string>
#include <pqxx/pqxx>

#include "DatabaseInfos.h"

class DatabaseConnection
{
private:
    DatabaseInfos m_connectionInfos;
    std::unique_ptr<pqxx::connection> m_connection;
public:
    /**
     * Creates the connection with the database directly.
     * Can throw an exception if error occured.
     */
    DatabaseConnection(DatabaseInfos connectionInfos);
    ~DatabaseConnection();

};

#endif // __DATABASECONNECTION_H__