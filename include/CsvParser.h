#ifndef __CSVPARSER_H__
#define __CSVPARSER_H__

#include <filesystem>
#include <fstream>
#include <vector>

#include "structs/PositionData.h"

class CsvParser
{
private:
    std::filesystem::path m_filePath;    
public:
    CsvParser(std::string filename);
    ~CsvParser();

    std::vector<PositionData> parsePositions();
};

#endif // __CSVPARSER_H__