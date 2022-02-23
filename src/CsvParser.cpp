#include "CsvParser.h"

using namespace std;
namespace fs = std::filesystem;

CsvParser::CsvParser(std::string filename) : m_filePath(filename), m_inputStream(m_filePath)
{
    string line;
    m_inputStream >> line;
    m_headers = splitLine(line, ';');
}

CsvParser::~CsvParser()
{}

vector<string> CsvParser::splitLine(string s, char delimiter)
{
    size_t startPosition = 0, endPosition;
    string token;
    vector<string> splitResult;

    while ((endPosition = s.find(delimiter, startPosition)) != string::npos)
    {
        token = s.substr(startPosition, endPosition - startPosition);
        startPosition = endPosition + 1;
        splitResult.push_back(token);
    }

    splitResult.push_back(s.substr(startPosition));
    return splitResult;
}

vector<PositionData> CsvParser::parsePositions()
{
    string line;
    vector<PositionData> positions;
    while (m_inputStream >> line)
    {
        auto splitted = splitLine(line, ';');

        PositionData positionData{
            splitted[0],
            splitted[1],
            splitted[2]
        };

        positions.push_back(positionData);
    }
    return positions;
}
