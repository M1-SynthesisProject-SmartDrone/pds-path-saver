#include "CsvParser.h"

using namespace std;
namespace fs = std::filesystem;

CsvParser::CsvParser(std::string filename) : m_filePath(filename)
{}

CsvParser::~CsvParser()
{}

vector<string> split(const string &str, char delimiter)
{
    vector<string> result;
    stringstream sstream;
    string item;

    while (getline(sstream, item, delimiter))
    {
        result.push_back(item);
    }
    return result;
}

vector<PositionData> CsvParser::parsePositions()
{
    string line;
    vector<PositionData> positions;
    ifstream inputStream(m_filePath);
    while(inputStream >> line)
    {
        auto splitted = split(line, ';');
        
        PositionData positionData{
            splitted[0],
            splitted[1],
            splitted[2]
        };

        positions.push_back(positionData);
    }
    return positions;
}
