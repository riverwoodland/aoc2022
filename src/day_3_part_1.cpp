#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_3.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    uint32_t prioritiesSum{0};

    std::string line;
    while (std::getline(fileStream, line))
    {
        const auto midIter = line.begin() + line.size() / 2;
        const std::set<char> firstCompartment{line.begin(), midIter};
        const std::set<char> secondCompartment{midIter, line.end()};

        char commonItem;
        std::set_intersection(firstCompartment.begin(), firstCompartment.end(), secondCompartment.begin(), secondCompartment.end(), &commonItem);

        prioritiesSum += (commonItem >= 'a' && commonItem <= 'z') ? commonItem - 'a' + 1 : commonItem - 'A' + 27;
    }

    std::cout << prioritiesSum << std::endl;
    return 0;
}
