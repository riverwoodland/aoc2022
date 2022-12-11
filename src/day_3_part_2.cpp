#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <array>
#include <vector>

bool getElfGroup(std::ifstream& fileStream, std::array<std::set<char>, 3>& elfGroup)
{
    for (size_t i = 0; i < elfGroup.size(); ++i)
    {
        std::string line;
        if (!std::getline(fileStream, line))
            return false;

        elfGroup[i] = std::set<char>(line.begin(), line.end());
    }

    return true;
}

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_3.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    uint32_t prioritiesSum{0};

    std::array<std::set<char>, 3> elfGroup;
    while (getElfGroup(fileStream, elfGroup))
    {
        std::vector<char> firstIntersection;
        std::set_intersection(elfGroup[0].begin(), elfGroup[0].end(), elfGroup[1].begin(), elfGroup[1].end(), std::back_inserter(firstIntersection));

        char badgeItem;
        std::set_intersection( firstIntersection.begin(), firstIntersection.end(), elfGroup[2].begin(), elfGroup[2].end(), &badgeItem );

        prioritiesSum += (badgeItem >= 'a' && badgeItem <= 'z') ? badgeItem - 'a' + 1 : badgeItem - 'A' + 27;
    }

    std::cout << prioritiesSum << std::endl;
    return 0;
}
