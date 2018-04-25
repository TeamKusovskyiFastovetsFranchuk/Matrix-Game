#include "task_1_40.h"
#include "expressions.h"

#include <regex>

std::string task_1_40(int id, const std::string& str)
{
    int a, b;
    std::regex reg("(-?\\d+),(-?\\d+)");
    std::cmatch match;

    if (!std::regex_match(str.c_str(), match, reg)) {
        return "fail";
    }

    a = std::stoi(match[1]);
    b = std::stoi(match[2]);

    float i;
    if (id <= 5) {
        i = Expression_1_5().integrate(a, b);
    }
    else if (id <= 10) {
        i = Expression_6_10().integrate(a, b);
    }
    else if (id <= 15) {
        i = Expression_11_15().integrate(a, b);
    }
    else if (id <= 20) {
        i = Expression_16_20().integrate(a, b);
    }
    else if (id <= 25) {
        i = Expression_21_25().integrate(a, b);
    }
    else if (id <= 30) {
        i = Expression_26_30().integrate(a, b);
    }
    else if (id <= 35) {
        i = Expression_31_35().integrate(a, b);
    }
    else if (id <= 40) {
        i = Expression_36_40().integrate(a, b);
    }

    int r = static_cast<int>(floor(i));

    return std::to_string(r);
}
