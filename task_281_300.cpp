#include "task_281_300.h"

#include <regex>
#include <cmath>

#include <QString>


std::string task_281_300(const std::string& str)
{
    int x, y, a;
    std::regex reg("\\{(-?\\d+),(-?\\d+)\\},(-?\\d+)");
    std::cmatch match;

    if (!std::regex_match(str.c_str(), match, reg)) {
        return "fail";
    }

    x = std::stoi(match[1]);
    y = std::stoi(match[2]);
    a = std::stoi(match[3]);

    float r_a = a / 180.0f * M_PI;

    float nx = x * cos(r_a) + y * sin(r_a);
    float ny = y * cos(r_a) - x * sin(r_a);

    QString format = "%1,%2";
    return format.arg(QString::number(nx, 'f', 2)).arg(QString::number(ny, 'f', 2)).toStdString();
}
