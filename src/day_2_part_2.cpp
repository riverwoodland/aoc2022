#include <fstream>
#include <iostream>
#include <sstream>
#include <array>

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_2.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    constexpr std::array< uint8_t, 9> results{{ 
        3, 1, 2, 
        4, 5, 6, 
        8, 9, 7
    }};

    uint64_t totalScore{0};

    std::string line;
    while (std::getline(fileStream, line))
    {
        char outcome{}, opponentPlay{};
        
        std::istringstream lineStream{std::move(line)};
        lineStream >> opponentPlay;
        lineStream.ignore();
        lineStream >> outcome;
        lineStream.ignore();

        totalScore += results[(outcome - 'X') * 3 + opponentPlay - 'A'];
    }

    std::cout << totalScore << std::endl;
    return 0;
}