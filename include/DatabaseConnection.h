#ifndef __DATABASECONNECTION_H__
#define __DATABASECONNECTION_H__

#include <string>
#include <vector>
#include <pqxx/pqxx>

#include "structs/DatabaseInfos.h"
#include "structs/PositionData.h"

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

    void addFlightPath(std::vector<PositionData> positions);
};

#endif // __DATABASECONNECTION_H__