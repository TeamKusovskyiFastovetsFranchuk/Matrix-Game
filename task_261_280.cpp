#include "task_261_280.h"
#include <cmath>

std::string task_261_280(const std::string& str)
{
    int x = 0, y = 0;
    bool xNeg = false, yNeg = false;
    
    int it = 0;

    xNeg = str[it] == '-';
    if (xNeg) {
        it++;
    }
    while (str[it] != ',') { // first number
        char c = str[it++];
        x = x * 10 + c - '0';
    }
    it++;

    yNeg = str[it] == '-';
    if (yNeg) {
        it++;
    }
    while (it < str.size()) { // second number
        char c = str[it++];
        y = y * 10 + c - '0';
    }

    if (xNeg) {
        x *= -1;
    }
    if (yNeg) {
        y *= -1;
    }

    float r = sqrt(x * x + y * y);
    float a = 0.0f;

    if (r > 0) {
        a = (acos(x / r) / M_PI) * 180.0f;
    }

    r = static_cast<int>(r * 100) / 100.0f;
    a = static_cast<int>(a * 100) / 100.0f;

    char out[50];
    sprintf(out, "%.2F,%.2F", r, a);
    return out;
}
