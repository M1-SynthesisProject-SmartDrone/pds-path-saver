#include "options_parser.h"

#include <cxxopts/cxxopts.hpp>

using namespace std;

void parseOptions(int argc, char *argv[], DatabaseInfos& dbInfos, InputInfos& inputInfos)
{
    cxxopts::Options options("pathSaver", "h");
    options.add_options()
        ("i,input_file", "The input for this process", cxxopts::value<string>())
        ("u,user", "Username for the database", cxxopts::value<string>()->default_value("tester"))
        ("d,db_name", "Name of the database", cxxopts::value<string>()->default_value("testdb"))
        ("P,password", "password for the database", cxxopts::value<string>()->default_value("testmdp"))
        ("h,host", "host of the database", cxxopts::value<string>()->default_value("127.0.0.1"))
        ("p,port", "port to access database", cxxopts::value<string>()->default_value("5432"));
    auto optionsParsed = options.parse(argc, argv);

    inputInfos.inputFilename = optionsParsed["input_file"].as<string>();
    
    dbInfos.username = optionsParsed["user"].as<string>();
    dbInfos.dbName = optionsParsed["db_name"].as<string>();
    dbInfos.password = optionsParsed["password"].as<string>();
    dbInfos.host = optionsParsed["host"].as<string>();
    dbInfos.port = optionsParsed["port"].as<string>();
}