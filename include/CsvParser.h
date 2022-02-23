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
    std::ifstream m_inputStream;
    std::vector<std::string> m_headers;

    std::vector<std::string> splitLine(std::string str, char delimiter);
public:
    CsvParser(std::string filename);
    ~CsvParser();

    std::vector<PositionData> parsePositions();
};

#endif // __CSVPARSER_H__