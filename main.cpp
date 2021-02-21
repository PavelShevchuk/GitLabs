#include "Stack.h"
#include "Calculator.h"

int main()
{
    Calculator calc;
    try{
        std::cout << calc.HandleExpression("(1+4)*5/2+3") << '\n' << calc.Check("(1+4)*5/2+3") << '\n' << calc.Calculate(calc.HandleExpression("(1+4)*5/2+3"));
    }
    catch(std::exception e){
        std::cout << e.what();
    }
    return 0;
}