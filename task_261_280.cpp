#include "task_261_280.h"

#include <regex>
#include <cmath>

#include <QString>

std::string task_261_280(const std::string& str)
{

    int x, y;
    std::regex reg("(-?\\d+),(-?\\d+)");
    std::cmatch match;

    if (!std::regex_match(str.c_str(), match, reg)) {
        return "fail";
    }

    x = std::stoi(match[1]);
    y = std::stoi(match[2]);

    float r = sqrt(x * x + y * y);
    float a = 0;

    if (r > 0) {
        a = acos(x / r) / M_PI * 180.0f;
    }

    QString format = "%1,%2";
    return format.arg(QString::number(r, 'f', 2)).arg(QString::number(a, 'f', 2)).toStdString();
}
