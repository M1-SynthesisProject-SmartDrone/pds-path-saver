#include "DatabaseConnection.h"

using namespace std;

DatabaseConnection::DatabaseConnection(DatabaseInfos infos)
{
    m_connectionInfos = infos;
    stringstream sstream;
    sstream << "user=" << infos.username
        << " password=" << infos.password
        << " dbname=" << infos.dbName
        << " hostaddr=" << infos.host
        << " port=" << infos.port;
    string connectionStr = sstream.str();

    m_connection = new pqxx::connection(connectionStr);
}

DatabaseConnection::~DatabaseConnection()
{}

string createQuery(string name, vector<PositionData>& positions)
{
    // Create the array 
    stringstream arrayStream;
    arrayStream << "ST_MakeLine(ARRAY[";
    for (const auto& p : positions)
    {
        arrayStream << "ST_MakePoint("
            << p.lat << ","
            << p.lon << ","
            << p.alt << "),";
    }
    // Overwrite the last ',' with the end of the array formatting
    arrayStream.seekp(-1, arrayStream.cur);
    arrayStream << "])";

    stringstream queryStream;
    queryStream << "INSERT INTO flight_path(name, path) VALUES ('"
        << name << "',"
        << arrayStream.str()
        << ");";
    return queryStream.str();
}

void DatabaseConnection::addFlightPath(vector<PositionData>& positions)
{
    // WARN : this implementation is not safe from SQL injection attacks, as 
    // the array insertion is very tedious to do with prepared statement
    string query = createQuery("", positions);
    pqxx::work transaction(*m_connection);
    transaction.exec(query);
    transaction.commit();
}
