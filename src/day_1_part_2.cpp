#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_1.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    uint32_t elfCalories{0};
    
    std::vector<uint32_t> top3ElfCalories( 3, 0 );

    std::string line;
    while (std::getline(fileStream, line))
    {
        if (!line.empty())
        {
            elfCalories += std::stoul(line); 
            continue;
        }

        if (auto it = std::min_element(top3ElfCalories.begin(), top3ElfCalories.end()); *it < elfCalories)
            *it = elfCalories;

        elfCalories = 0;
    }

    std::cout << std::accumulate(top3ElfCalories.begin(), top3ElfCalories.end(), 0) << std::endl;
    return 0;
}