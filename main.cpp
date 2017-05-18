#include <iostream>
#include "Interpreter.hpp"

int main()
{
    ebfi::Interpreter interpreter;
    interpreter.setSourceCode("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.");
    interpreter.executeCode();

    return 0;
}