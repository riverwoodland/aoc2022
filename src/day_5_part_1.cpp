#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

void parseRow(std::vector<std::vector<char>>& crateColumns, const std::string& row)
{
    for (auto idx = row.find('['); idx != std::string::npos; idx = row.find('[', idx + 1))
        crateColumns[idx/4].push_back(row[idx + 1]);
}

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_5.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(fileStream, line);

    std::vector<std::vector<char>> crateColumns;
    crateColumns.resize((line.size() + 1) / 4);

    parseRow(crateColumns, line);

    while (std::getline(fileStream, line))
    {
        if (line.empty())
            break;

        parseRow(crateColumns, line);
    }

    for (auto& column : crateColumns)
        std::reverse(column.begin(), column.end());

    while (std::getline(fileStream, line))
    {
        uint32_t moveCount{ 0 }, srcColumnIdx{ 0 }, dstColumnIdx{ 0 };

        std::stringstream lineStream{ std::move(line) };
        lineStream.ignore(5);
        lineStream >> moveCount;
        lineStream.ignore(6);
        lineStream >> srcColumnIdx;
        lineStream.ignore(4);
        lineStream >> dstColumnIdx;
        lineStream.ignore(1);

        auto& dstColumn = crateColumns[ dstColumnIdx - 1 ];
        auto& srcColumn = crateColumns[ srcColumnIdx - 1 ];

        dstColumn.insert(dstColumn.end(), srcColumn.rbegin(), srcColumn.rbegin() + moveCount);
        srcColumn.erase(srcColumn.end() - moveCount , srcColumn.end());
    }

    for (const auto& column : crateColumns)
    {
        if (column.empty())
            std::cout << "-";
        else
            std::cout << column.back() << "";
    }

    std::cout << std::endl;
    return 0;
}
