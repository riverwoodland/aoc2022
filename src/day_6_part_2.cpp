#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <set>

int main(int /*unused*/, char** /*unused*/)
{
    std::ifstream fileStream("../inputs/day_6.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    constexpr auto RequiredDistinctCount = 14;

    std::array<char, RequiredDistinctCount> buffer;
    fileStream.read(buffer.data(), RequiredDistinctCount - 1);

    auto markerIdx{fileStream.gcount()};
    while (fileStream.read(&buffer[RequiredDistinctCount - 1], 1))
    {
        ++markerIdx;
        
        std::set<char> uniqueChars{buffer.begin(), buffer.end()};
        if (uniqueChars.size() == RequiredDistinctCount)
            break;

        std::rotate(buffer.begin(), buffer.begin() + 1, buffer.end());
    }

    std::cout << markerIdx << std::endl;
    return 0;
}
