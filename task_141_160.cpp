#include "task_141_160.h"

#include <regex>
#include <cmath>
#include <QDebug>

std::string task_141_160(const std::string& str)
{
    std::regex reg("\\{(-?\\d+),(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+),(-?\\d+)\\}");
    std::cmatch match;

    if (!std::regex_match(str.c_str(), match, reg)) {
        return "fail";
    }

    int i0 = std::stoi(match[1]);
    int j0 = std::stoi(match[2]);
    int k0 = std::stoi(match[3]);

    int i1 = std::stoi(match[4]);
    int j1 = std::stoi(match[5]);
    int k1 = std::stoi(match[6]);

    int i2 = std::stoi(match[7]);
    int j2 = std::stoi(match[8]);
    int k2 = std::stoi(match[9]);

    int i3 = j0 * k1 - j1 * k0;
    int j3 = i1 * k0 - i0 * k1;
    int k3 = i0 * j1 - i1 * j0;

    int r = i2 * i3 + j2 * j3 + k2 * k3;
    r = abs(r);
    return std::to_string(r);
}
