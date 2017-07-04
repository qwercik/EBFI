#include <array>
#include <stack>
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
	
	std::stack<uint32_t> stack;
	
	int loops_counter = 0;

    for (int instruction_pointer = 0; instruction_pointer < source_code.size(); ++instruction_pointer)
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
                std::cout << memory[memory_pointer];
                break;

            case ',':
                memory[memory_pointer] = std::cin.get();
                break;

			case '[':
				++loops_counter;

				if (memory[memory_pointer])
				{
					stack.push(instruction_pointer);
				}
				else
				{
					while (loops_counter)
					{
						++instruction_pointer;

						if (source_code[instruction_pointer] == ']')
							--loops_counter;
					}

					--instruction_pointer;
				}
				
				break;

			case ']':
				--loops_counter;

				if (memory[memory_pointer])
					instruction_pointer = stack.top() - 1;

				stack.pop();
				
				break;
        }
    }
}


