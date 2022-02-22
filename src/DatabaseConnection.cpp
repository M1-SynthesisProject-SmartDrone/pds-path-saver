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

