#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string_view>
#include <utility>
#include <unordered_map>
#include <limits>

void cd(std::string dstDir, std::string& cwd, std::vector<size_t>& cwdSegmentLengths)
{
    if (dstDir == "..")
    {
        cwd.erase(cwd.end() - cwdSegmentLengths.back(), cwd.end());
        cwdSegmentLengths.pop_back();
        return;
    }

    if (dstDir == "/")
    {
        cwd.clear();
        cwdSegmentLengths.clear();
    }

    cwdSegmentLengths.push_back(dstDir.size());
    cwd.append(std::move(dstDir));
}

size_t filesSize(std::ifstream& fileStream, std::string& line)
{
    size_t cwdSize{0};
    while(std::getline(fileStream, line) && line.front() != '$')
    {
        if (auto attribute = line.substr(0, line.find(" ")); attribute != "dir")
            cwdSize += std::stoul(attribute);
    }

    return cwdSize;
}

void updDirsSizes(const std::string& cwd, const std::vector<size_t>& cwdSegmentLengths, size_t cwdSize, std::unordered_map<std::string, size_t>& dirSizes)
{
    size_t cwdCursor = 0;
    for (auto it = cwdSegmentLengths.begin(); it != cwdSegmentLengths.end(); ++it)
    {
        cwdCursor += *it;
        dirSizes[cwd.substr(0, cwdCursor)] += cwdSize;
    }
}

int main(int /*argc*/, char** /*argv*/)
{
    std::ifstream fileStream("../inputs/day_7.txt");
    if (!fileStream.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return 1;
    }

    constexpr std::string_view CdCommand = "$ cd ";
    constexpr std::string_view LsCommand = "$ ls";

    std::string cwd;
    std::vector<size_t> cwdSegmentLengths;
    std::unordered_map<std::string, size_t> dirSizes;

    std::string line;
    while (std::getline(fileStream, line))
    {
        if (line.find(LsCommand) == 0 && dirSizes.find(cwd) == dirSizes.end())
            updDirsSizes(cwd, cwdSegmentLengths, filesSize(fileStream, line), dirSizes);

        if (line.find(CdCommand) == 0)
            cd(line.substr(CdCommand.size(), std::string::npos), cwd, cwdSegmentLengths);
    }

    constexpr size_t TotalDiskSpace = 70'000'000;
    constexpr size_t TargetFreeSpace = 30'000'000;

    const auto unusedSpace = TotalDiskSpace - dirSizes["/"];

    size_t minTargetDirSize = std::numeric_limits<size_t>::max();
    for (const auto& [_, dirSize] : dirSizes)
    {
        if (unusedSpace + dirSize >= 30'000'000 && dirSize < minTargetDirSize)
            minTargetDirSize = dirSize;
    }

    std::cout << minTargetDirSize << std::endl;
    return 0;
}
