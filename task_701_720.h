#ifndef TASK_701_720_H
#define TASK_701_720_H

#include <string>
#include <queue>
#include <stack>
#include <cctype>

namespace calculator
{
    enum class ErrorType
    {
        NONE,
        OPERATOR_MISSED,
        OPERAND_MISSED,
        UNEXPECTED_SYMBOL,
        TOO_MANY_OPEN_BRACKET,
        TOO_MANY_CLOSE_BRACKET, 
        UNDEF_ERROR
    };


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

    ErrorType error = ErrorType::NONE;
    int tmpNumber = 0;
    int countBracket = 0;
    int indexLastPart = -1;
    int i;

    for (i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isDelim(c)) {
            continue;
        }
        if (c == '(') {
            if (indexLastPart != -1 && !(isOperator(str[indexLastPart]) || str[indexLastPart] == '(')) {
                error = ErrorType::OPERATOR_MISSED;
                break;
            }
            operations.push('(');
            countBracket++;
        }
        else if (c == ')') {
            if (indexLastPart != -1 && (isOperator(str[indexLastPart]) || str[indexLastPart] == '(')) {
                error = ErrorType::OPERAND_MISSED;
                break;
            }
            while (!operations.empty() && operations.top() != '(') {
                computeOperation(values, operations.top());
                operations.pop();
            }
            if (operations.empty()) {
                error = ErrorType::TOO_MANY_CLOSE_BRACKET;
                break;
            }
            operations.pop();
            countBracket--;
        }
        else if (isOperator(c)) {
            if (indexLastPart == -1 || !(isDigit(str[indexLastPart]) || str[indexLastPart] == ')')) {
                error = ErrorType::OPERAND_MISSED;
                break;
            }
            while (!operations.empty() && priority(operations.top()) >= priority(c)) {
                computeOperation(values, operations.top());
                operations.pop();
            }
            operations.push(c);
        }
        else if (isDigit(c)) {
            if (indexLastPart != -1 && (isDigit(str[indexLastPart]) || str[indexLastPart] == ')')) { // operator missed
                error = ErrorType::OPERATOR_MISSED;
                break;
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
            error = ErrorType::UNEXPECTED_SYMBOL;
            break;
        }
        indexLastPart = i;
    }

    if (error == ErrorType::NONE) {
        if (values.empty()) {
            error = ErrorType::UNDEF_ERROR;
        }
        if (indexLastPart != -1 && isOperator(str[indexLastPart])) {
            error = ErrorType::OPERAND_MISSED;
        }
        else if (countBracket % 2 == 1) {
            error = ErrorType::TOO_MANY_OPEN_BRACKET;
        }
    }

    // handle error
    switch(error) {
    case ErrorType::UNDEF_ERROR:
        return "UNDEF_ERROR";
    case ErrorType::UNEXPECTED_SYMBOL:
        return std::string("UNEXPECTED_SYMBOL,") + str[i];
    case ErrorType::TOO_MANY_OPEN_BRACKET:
        return "TOO_MANY_(";
    case ErrorType::TOO_MANY_CLOSE_BRACKET:
        return "TOO_MANY_)";
    case ErrorType::OPERATOR_MISSED:
        return std::string("OPERATOR_MISSED,") + std::string(str, indexLastPart, i - indexLastPart + 1);
    case ErrorType::OPERAND_MISSED:
        std::string msg("OPERAND_MISSED,");
        if (indexLastPart == -1) {
            msg += std::string(str, 0, i + 1);
        }
        else if (indexLastPart == i) {
            msg += std::string(str, i, str.size() - i);
        }
        else {
            msg += std::string(str, indexLastPart, i - indexLastPart + 1);
        }
        return msg;
    }

    while(!operations.empty()){
        computeOperation(values, operations.top());
        operations.pop();
    }
    return std::to_string(values.top()); 
}

#endif