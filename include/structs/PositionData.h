#ifndef __POSITIONDATA_H__
#define __POSITIONDATA_H__

#include <string>

typedef struct position_data_t
{
    std::string lat;
    std::string lon;
    std::string alt;
} PositionData;

#endif // __POSITIONDATA_H__