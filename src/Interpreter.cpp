#include <string>
#include <array>
#include <stack>
#include <fstream>
#include <cstdint>
#include <iostream>
#include "Interpreter.hpp"

ebfi::Interpreter::Interpreter()
{

}

void ebfi::Interpreter::setCode(const std::string& source_code)
{
	this->source_code = source_code;
}

bool ebfi::Interpreter::loadCodeFromFile(const std::string& filename)
{
	std::ifstream code_file(filename, std::ios::binary);

	if (!code_file.is_open())
		return false;

	std::string source_code;
	std::getline(code_file, source_code, '\0');

	setCode(source_code);

	return true;
}

void ebfi::Interpreter::executeCode()
{
	std::array<uint8_t, 30000> memory;
	memory.fill(0);
	uint32_t memory_pointer = 0;
	
	int loops_counter = 0;
	std::stack<uint32_t> stack;

	for (uint32_t instruction_pointer = 0; instruction_pointer < source_code.size(); ++instruction_pointer)
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
				if (memory[memory_pointer])
				{
					stack.push(instruction_pointer);
				}
				else
				{
					++instruction_pointer;
					while (loops_counter > 0 || source_code[instruction_pointer] != ']')
					{
						if (source_code[instruction_pointer] == '[')
							loops_counter++;
						else if (source_code[instruction_pointer] == ']')
							loops_counter--;

						++instruction_pointer;
					}
				}

				break;

			case ']':
				if (memory[memory_pointer])
					instruction_pointer = stack.top() - 1;
				
				stack.pop();
				break;
		}
	}	
}

