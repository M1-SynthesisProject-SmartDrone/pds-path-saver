#include "DatabaseConnection.h"

using namespace std;

DatabaseConnection::DatabaseConnection(DatabaseInfos infos)
{
    m_connectionInfos = infos;
    stringstream sstream;
    sstream << "user=" << infos.username
            << " password" << infos.password
            << " dbname=" << infos.dbName
            << " hostaddr=" << infos.host
            << " port=" << infos.port;
    string connectionStr = sstream.str();

    m_connection = make_unique<pqxx::connection>(connectionStr);
}

DatabaseConnection::~DatabaseConnection()
{}

void addFlightPath(std::vector<PositionData> positions)
{
    // WARN : this implementation is not safe from SQL injection attacks, as 
    // the array insertion is very tedious to do with prepared statement

    // TODO 
}
