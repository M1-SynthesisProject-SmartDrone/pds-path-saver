#ifndef __DATABASEINFOS_H__
#define __DATABASEINFOS_H__

#include <string>

typedef struct database_infos_t
{
    std::string username;
    std::string password;
    std::string host;
    std::string port;
    std::string dbName;
} DatabaseInfos;

#endif // __DATABASEINFOS_H__