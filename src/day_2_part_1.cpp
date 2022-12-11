#include <fstream>
#include <iostream>
#include <array>
#include <sstream>

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_2.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    constexpr std::array< uint8_t, 9> results{{
        4, 1, 7, 
        8, 5, 2, 
        3, 9, 6
    }};

    uint64_t totalScore{0};

    std::string line;
    while (std::getline(fileStream, line))
    {
        char myPlay{}, opponentPlay{};
        
        std::istringstream lineStream{std::move(line)};
        lineStream >> opponentPlay;
        lineStream.ignore();
        lineStream >> myPlay;
        lineStream.ignore();

        totalScore += results[(myPlay - 'X') * 3 + opponentPlay - 'A'];
    }

    std::cout << totalScore << std::endl;
    return 0;
}