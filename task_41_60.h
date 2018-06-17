#include <string>
#include <regex>
#include <utility>
#include <cstdio>


std::string task_41_60(std::string& str)
{
    std::regex reg("(-?\\d+),(-?\\d+),(-?\\d+)");
    std::cmatch result;

    if (!std::regex_match(str.c_str(), result, reg)) {
        return "fail";
    } 

    float a = std::stof(result[1]);
    float b = std::stof(result[2]);
    float c = std::stof(result[3]);

    float d = b * b - 4 * a * c;

    char out[50];
    if (d == 0.0f) {
        float x = (-b + sqrt(d)) / (2 * a);
        x = static_cast<int>(x * 100) / 100.0f;
        sprintf(out, "%.2F,%.2F", x, x);
    }
    else if (d > 0.0f) {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);
        x1 = static_cast<int>(x1 * 100) / 100.0f;
        x2 = static_cast<int>(x2 * 100) / 100.0f;
        if (x1 > x2) { // sort
            std::swap(x1, x2);
        }
        sprintf(out, "%.2F,%.2F", x1, x2);
    }
    else if (d < 0.0f) {
        float r, i;
        r = -b / (2 * a);
        i = fabs(sqrt(-d) / (2 * a));

        r = static_cast<int>(r * 100) / 100.0f;
        i = static_cast<int>(i * 100) / 100.0f;

        sprintf(out, "%.2F,%.2Fi", r, i);
    }

    return out;
}