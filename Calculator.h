#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "Stack.h"

class Calculator {
public:
    std::string HandleExpression(std::string inputString);
    double Calculate(const std::string& opz);
    bool Check(const std::string& string);
};
#endif