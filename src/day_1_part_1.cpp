#include <fstream>
#include <iostream>
#include <string>

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_1.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    uint32_t elfCalories{0}, maxElfCalories{0};

    std::string line;
    while (std::getline(fileStream, line))
    {
        if (line.empty())
        {
            maxElfCalories = std::max(elfCalories, maxElfCalories);
            elfCalories = 0;
            continue;
        }

        elfCalories += std::stoul(line);
    }

    std::cout << maxElfCalories << std::endl;
    return 0;
}