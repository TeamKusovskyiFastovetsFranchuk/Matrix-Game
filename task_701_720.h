#ifndef TASK_701_720_H
#define TASK_701_720_H

#include <string>
#include <queue>
#include <stack>

namespace Calculator
{
    class Expression
    {
        char m_op;
        int m_value;
    public:
        Expression(char op) : m_op(op) { }
        Expression(int value) : m_value(value), m_op('\0') { }
        bool isOperation() const { return m_op != '\0'; }
        int value() const { return m_value; }
        int exec(int v1, int v2) const
        {
            switch(m_op)
            {
            case '+':
                return v1 + v2;
            case '-':
                return v1 - v2;
            case '*':
                return v1 * v2;
            case '/':
                return v1 / v2;
            }
            return 0;
        }
    };
}

std::string task_701_720(std::string const& str)
{
    using Calculator::Expression;
    std::queue<Expression> rpn;

    std::stack<int> values;
    while (!rpn.empty()) {
        Expression& expr = rpn.front();
        if (expr.isOperation()) {
            int v1 = values.top(); values.pop();
            int v2 = values.top(); values.pop();
            values.push(expr.exec(v1, v2));
        }
        else {
            values.push(expr.value());
        }
        rpn.pop();
    }
    return std::to_string(values.top());
}

#endif