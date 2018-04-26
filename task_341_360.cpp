#include "task_341_360.h"

#include <regex>
#include <cmath>

std::string task_341_360(const std::string& str)
{
    std::regex reg("\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\}");
    std::cmatch match;

    if (!std::regex_match(str.c_str(), match, reg)) {
        return "fail";
    }

    int x0 = std::stoi(match[1]);
    int y0 = std::stoi(match[2]);

    int x1 = std::stoi(match[3]);
    int y1 = std::stoi(match[4]);

    int x2 = std::stoi(match[5]);
    int y2 = std::stoi(match[6]);

    int i0 = x0 - x1;
    int j0 = y0 - y1;

    int i1 = x2 - x1;
    int j1 = y2 - y1;

    int dot = i0 * j1 - i1 * j0;

    bool clockwise = dot > 0;
    return clockwise ? "1" : "0";
}
