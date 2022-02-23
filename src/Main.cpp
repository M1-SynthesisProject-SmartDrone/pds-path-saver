/**
 * This program will take a filename as input and insert to a database
 * (PostgreSQL one) 
 */

#include <iostream>
#include <vector>
#include <functional>

#include "options_parser.h"
#include "DatabaseConnection.h"
#include "CsvParser.h"

using namespace std;

// #define DEBUG

int main(int argc, char *argv[])
{
    DatabaseInfos dbInfos;
    InputInfos inputInfos;
    try 
    {
        parseOptions(argc, argv, dbInfos, inputInfos);
        DatabaseConnection databaseConnection(dbInfos);

        CsvParser parser(inputInfos.inputFilename);
        vector<PositionData> positions = parser.parsePositions();
#ifdef DEBUG
        for_each(positions.begin(), positions.end(), [](PositionData p) {printf("%s - %s - %s\n", p.lat.c_str(), p.lon.c_str(), p.alt.c_str());});
#endif
        databaseConnection.addFlightPath(positions);
    } 
    catch (std::exception& e)
    {
        cerr << "Error while saving path : " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
