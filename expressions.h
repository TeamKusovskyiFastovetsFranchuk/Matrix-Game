#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

class Expression
{
public:
    const int COUNT_STEPS = 20;

    virtual double exec(double x) const = 0;

    double integrate(int a, int b) const;
};

#endif // EXPRESSIONS_H

class Expression_1_5 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_6_10 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_11_15 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_16_20 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_21_25 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_26_30 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_31_35 : public Expression
{
public:
    double exec(double x) const override;
};

class Expression_36_40 : public Expression
{
public:
    double exec(double x) const override;
};
