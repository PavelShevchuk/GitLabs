#include "Calculator.h"

std::string Calculator::HandleExpression(std::string inputString) {
    std::string outputString;
    std::string::size_type ind;
    while ((ind = inputString.find(' ')) != std::string::npos) {
        inputString.erase(ind, 1);
    }

    std::map<char, int> map;
    map.insert(std::make_pair('^', 4));
    map.insert(std::make_pair('*', 3));
    map.insert(std::make_pair('/', 3));
    map.insert(std::make_pair('+', 2));
    map.insert(std::make_pair('-', 2));
    map.insert(std::make_pair('(', 1));

    Stack<char> container;
    bool globalFlag = true;
    bool flag = true;
    bool bracketFlag = false;
    for (auto c : inputString) {
        if (!isalnum(c)) {
            if (((globalFlag) || (bracketFlag)) && (c == '-')) {
                outputString += c;
                continue;
            }
            if (c == '.') {
                outputString += c;
                continue;
            }
            if (flag) {
                outputString += ' ';
                flag = false;
            }
            if (')' == c) {
                while (container.Top() != '(') {
                    outputString += container.Top();
                    container.Pop();
                    outputString += ' ';
                }
                container.Pop();
            }
            else if ('(' == c) {
                container.Push(c);
                bracketFlag = true;
            }
            else if (container.isEmpty() || (map[container.Top()] < map[c])) {
                container.Push(c);
            }
            else {
                do {
                    outputString += container.Top();
                    outputString += ' ';
                    container.Pop();
                } while (!(container.isEmpty() || (map[container.Top()] < map[c])));
                container.Push(c);
            }
        }
        else {
            flag = true;
            bracketFlag = false;
            outputString += c;
        }
        if (globalFlag) {
            globalFlag = false;
        }
    }
    if (flag) { outputString += ' '; }
    while (!container.isEmpty()) {
        outputString += container.Top();
        outputString += ' ';
        container.Pop();
    }
    return outputString;
}

bool Calculator::Check(const std::string& string) {
    Stack<int> stack;
    for (auto c : string) {
        if (c == '(') {
            stack.Push(1);
        }
        else if ((c == ')') && (stack.getSize() > 0)) {
            stack.Pop();
        }
        else if ((c == ')') && (stack.getSize() <= 0)) {
            return false;
        }
    }
    if (stack.getSize() > 0) {
        return false;
    }
    for (int i = 0; i < (int)string.size() - 1; ++i) {
        if (((!isdigit(string[i])) && (string[i] != ')') && (string[i] != '(')) &&
            ((!isdigit(string[i + 1])) && (string[i + 1] != ')') && (string[i + 1] != '('))) {
            return false;
        }
    }
    for (int i = string.size() - 1; (i >= 0) && (!isdigit(string[i])); --i) {
        if ((string[i] != ')') && (string[i] != '(')) {
            return false;
        }
    }
    for (auto c : string) {
        if ((c != '+') && (c != '-') && (c != '/') && (c != '*') && (c != '^') && (c != '.') && (!isdigit(c)) && (c != ')') && (c != '(')) {
            return false;
        }
    }
    return true;
}

double Calculator::Calculate(const std::string& opz) {
    if (opz.empty()) {
        throw std::exception("Calculating: There is no expression!");
    }
    Stack<double> container;
    std::string numberString;
    double number;
    std::stringstream stringStream(opz);
    while (stringStream >> numberString) {
        if ((numberString == "+") || (numberString == "-") || (numberString == "/") || (numberString == "*") || (numberString == "^")) {
            double b = container.Top();
            container.Pop();
            double a = container.Top();
            container.Pop();
            if (numberString == "+") {
                a = a + b;
                container.Push(a);
            }
            else if (numberString == "-") {
                a = a - b;
                container.Push(a);
            }
            else if (numberString == "*") {
                a = a * b;
                container.Push(a);
            }
            else if (numberString == "/") {
                a = a / b;
                container.Push(a);
            }
            else if (numberString == "^") {
                a = std::pow(a, b);
                container.Push(a);
            }
        }
        else {
            number = std::stod(numberString);
            container.Push(number);
            numberString.clear();
        }
    }
    return container.Top();
}