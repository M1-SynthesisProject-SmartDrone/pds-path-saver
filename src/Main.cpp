/**
 * This program will take a filename as input and insert to a database
 * (PostgreSQL one) 
 */

#include <iostream>
#include <vector>

#include "options_parser.h"
#include "DatabaseConnection.h"

using namespace std;

int main(int argc, char *argv[])
{
    DatabaseInfos dbInfos;
    InputInfos inputInfos;
    try 
    {
        parseOptions(argc, argv, dbInfos, inputInfos);
        DatabaseConnection databaseConnection(dbInfos);

        
    } 
    catch (std::exception& e)
    {
        cerr << "Error while saving path : " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}