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
    int countBracket = 0;
    int indexLastPart = -1;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isDelim(c)) {
            continue;
        }
        if (c == '(') {
            if (indexLastPart != -1 && isDigit(str[indexLastPart])) { // operator missed
                return std::string("OPERATOR_MISSED,") + std::string(str, indexLastPart, i - indexLastPart + 1);
            }
            operations.push('(');
            countBracket++;
        }
        else if (c == ')') {
            while (!operations.empty() && operations.top() != '(') {
                computeOperation(values, operations.top());
                operations.pop();
            }
            if (operations.empty()) { // too many ')'
                return "TOO_MANY_)";
            }
            operations.pop();
            countBracket--;
        }
        else if (isOperator(c)) {
            if (indexLastPart != -1 && !(isDigit(str[indexLastPart]) || str[indexLastPart] == ')')) { // operand missed
                return std::string("OPERAND_MISSED,") + std::string(str, indexLastPart, i - indexLastPart + 1);
            }

            while (!operations.empty() && priority(operations.top()) >= priority(c)) {
                computeOperation(values, operations.top());
                operations.pop();
            }
            operations.push(c);
        }
        else if (isDigit(c)) {
            if (indexLastPart != -1 && isDigit(str[indexLastPart])) { // operator missed
                return std::string("OPERATOR_MISSED,") + std::string(str, indexLastPart, i - indexLastPart + 1);
            }
            tmpNumber = c - '0';
            i++;
            while (i < str.size() && isDigit(str[i])) {
                tmpNumber = tmpNumber * 10 + str[i] - '0';
                i++;
            }
            i--;
            values.push(tmpNumber);
        }
        else {
            return std::string("UNEXPECTED_SYMBOL,") + c;
        }
        indexLastPart = i;
    }
    if (countBracket % 2 == 1) { // too many '('
        return "TOO_MANY_(";
    }
    while(!operations.empty()){
        computeOperation(values, operations.top());
        operations.pop();
    }
    return std::to_string(values.top()); 
}

#endif