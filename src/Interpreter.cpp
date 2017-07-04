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
	std::ifstream code_file(filename, std::ios::binary | std::ios::ate);

	if (!code_file.is_open())
		return false;

	std::size_t code_size = code_file.tellg();
	code_file.seekg(0);

	std::string source_code(code_size, '\0');
	code_file.read(&source_code[0], code_size);

	setCode(source_code);

	return true;
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


