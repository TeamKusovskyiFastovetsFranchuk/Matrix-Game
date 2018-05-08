#ifndef TASK_701_720_H
#define TASK_701_720_H

#include <string>
#include <queue>
#include <stack>
#include <cctype>

namespace calculator
{
    inline bool isDelim(char c) { return isspace(c); }
    inline bool isDigit(char c) { return isdigit(c); }
    inline bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
    inline int priority(char c) 
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        return -1;
    }

    void computeOperation(std::stack<int>& values, char op)
    {
        int v2 = values.top();
        values.pop();
        int v1 = values.top();
        values.pop();
        switch (op) {
        case '+':
            values.push(v1 + v2);
            break;
        case '-':
            values.push(v1 - v2);
            break;
        case '*':
            values.push(v1 * v2);
            break;
        case '/':
            values.push(v1 / v2);
            break;
        }
    }
}

std::string task_701_720(std::string const& str)
{
    using namespace calculator;

    std::stack<int> values;
    std::stack<char> operations;

    int tmpNumber = 0;
    int indexPrevOperator = -1;
    int indexPrevOperand = -1;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isDelim(c)) {
            continue;
        }
        if (c == '(') {
            operations.push('(');
        }
        else if (c == ')') {
            while (operations.top() != '(') {
                computeOperation(values, operations.top());
                operations.pop();
            }
            operations.pop();
        }
        else if (isOperator(c)) {
            while (!operations.empty() && priority(operations.top()) >= priority(c)) {
                computeOperation(values, operations.top());
                operations.pop();
            }
            operations.push(c);
        }
        else if (isDigit(c)) {
            tmpNumber = c - '0';
            i++;
            while (i < str.size() && isDigit(str[i])) {
                tmpNumber = tmpNumber * 10 + str[i] - '0';
                i++;
            }
            i--;
            indexPrevOperand = i;
            values.push(tmpNumber);
        }
        else {
            return std::string("UNEXPECTED_SYMBOL,") + c;
        }
    }
    while(!operations.empty()){
        computeOperation(values, operations.top());
        operations.pop();
    }
    return std::to_string(values.top()); 
}

#endif