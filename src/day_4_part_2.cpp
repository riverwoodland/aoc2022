#include <fstream>
#include <iostream>
#include <utility>
#include <sstream>

int main(int /*unused*/, char** /*unused*/)
{
    std::ifstream fileStream("../inputs/day_4.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    uint32_t overlappingSections{0};

    std::string line;
    while (std::getline(fileStream, line))
    {
        std::pair<uint32_t, uint32_t> firstSection, secondSection;

        std::stringstream lineStream(std::move(line));
        lineStream >> firstSection.first;
        lineStream.ignore();
        lineStream >> firstSection.second;
        lineStream.ignore();
        lineStream >> secondSection.first;
        lineStream.ignore();
        lineStream >> secondSection.second;
        lineStream.ignore();

        if (firstSection.first <= secondSection.first && firstSection.second >= secondSection.first)
            ++overlappingSections;
        else if (secondSection.first <= firstSection.first && secondSection.second >= firstSection.first)
            ++overlappingSections;
    }

    std::cout << overlappingSections << std::endl;
    return 0;
}