#include "task_1_40.h"
#include <cmath>

int const COUNT_STEPS = 72;

double expression_1_5(double x)
{
    double result;
    result = pow(3, sin(x));
    return result;
}

double expression_6_10(double x)
{
    double result;
    result = pow(2, cos(x));
    return result;
}

double expression_11_15(double x)
{
    double result;
    result = x + sin(x * x * x);
    return result;
}

double expression_16_20(double x)
{
    double result;
    result = x + cos(x * x);
    return result;
}

double expression_21_25(double x)
{
    double result;
    result = log10(x + sin(x));
    return result;
}

double expression_26_30(double x)
{
    double result;
    result = (x + sin(x)) / log10(x);
    return result;
}

double expression_31_35(double x)
{
    double result;
    result = (x - cos(x)) / log10(x);
    return result;
}

double expression_36_40(double x)
{
    double result;
    result = atan(exp(sin(x)));
    return result;
}

using Func = double (*)(double);

double integrate(int a, int b, Func f)
{
    double h = static_cast<double>(b - a) / COUNT_STEPS;
    double sum = 0;

    double x0 = a;
    double x1 = a + h;

    for (int i = 0; i < COUNT_STEPS; i++) {
        sum += f(x0) + 4 * f(x0 + h / 2) + f(x1);
        x0 += h;
        x1 += h;
    }
    return (h / 6) * sum;
}

std::string task_1_40(int id, std::string const& str)
{
    int a = 0, b = 0;
    bool aNeg = false, bNeg = false;
    
    int it = 0;

    aNeg = str[it] == '-';
    if (aNeg) {
        it++;
    }
    while (str[it] != ',') { // first number
        char c = str[it++];
        a = a * 10 + c - '0';
    }
    it++;

    bNeg = str[it] == '-';
    if (bNeg) {
        it++;
    }
    while (it < str.size()) { // second number
        char c = str[it++];
        b = b * 10 + c - '0';
    }

    if (aNeg) {
        a *= -1;
    }
    if (bNeg) {
        b *= -1;
    }

    Func f;
    if (id <= 5) {
        f = &expression_1_5;
    }
    else if (id <= 10) {
        f = &expression_6_10;
    }
    else if (id <= 15) {
        f = &expression_11_15;
    }
    else if (id <= 20) {
        f = &expression_16_20;
    }
    else if (id <= 25) {
        f = &expression_21_25;
    }
    else if (id <= 30) {
        f = &expression_26_30; 
    }
    else if (id <= 35) {
        f = &expression_31_35;
    }
    else if (id <= 40) {
        f = &expression_36_40;
    }

    int r = static_cast<int>(floor(integrate(a, b, f)));
    return std::to_string(r);
}
