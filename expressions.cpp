#include "expressions.h"
#include <cmath>

double Expression::integrate(int a, int b) const
{
    double h = static_cast<double>(b - a) / COUNT_STEPS;
    double sum = 0;

    double x0 = a;
    double x1 = a + h;

    for (int i = 0 ; i < COUNT_STEPS; i++) {

        sum += this->exec(x0) + 4 * this->exec(x0 + h / 2) + this->exec(x1);

        x0 += h;
        x1 += h;
    }

    return (h / 6) * sum;
}

double Expression_1_5::exec(double x) const
{
    double result;
    result = pow(3, sin(x));
    return result;
}

double Expression_6_10::exec(double x) const
{
    double result;
    result = pow(2, cos(x));
    return result;
}

double Expression_11_15::exec(double x) const
{
    double result;
    result = x + sin(x * x * x);
    return result;
}

double Expression_16_20::exec(double x) const
{
    double result;
    result = x + cos(x * x);
    return result;
}

double Expression_21_25::exec(double x) const
{
    double result;
    result = log10(x + sin(x));
    return result;
}

double Expression_26_30::exec(double x) const
{
    double result;
    result = (x + sin(x)) / log10(x);
    return result;
}

double Expression_31_35::exec(double x) const
{
    double result;
    result = (x - cos(x)) / log10(x);
    return result;
}

double Expression_36_40::exec(double x) const
{
    double result;
    result = atan(exp(sin(x)));
    return result;
}
