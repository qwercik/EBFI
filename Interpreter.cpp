#include <array>
#include <stdint.h>
#include <iostream>
#include "Interpreter.hpp"

ebfi::Interpreter::Interpreter()
{

}

void ebfi::Interpreter::setSourceCode(const std::string& source_code)
{
    this->source_code = source_code;
}

void ebfi::Interpreter::executeCode()
{
    std::array<uint8_t, 30000> memory;
    uint32_t memory_pointer = 0;

    for (int instruction_pointer = 0; instruction_pointer < source_code.size();)
    {
        switch (source_code[instruction_pointer])
        {
            case '>':
                memory_pointer++;
                break;

            case '<':
                memory_pointer--;
                break;

            case '+':
                ++memory[memory_pointer];
                break;

            case '-':
                --memory[memory_pointer];
                break;

            case '.':
                std::cout << static_cast<char>(memory[memory_pointer]);
                break;

            case ',':
                memory[memory_pointer] = std::cin.get();
                break;
        }

        ++instruction_pointer;
    }
}


