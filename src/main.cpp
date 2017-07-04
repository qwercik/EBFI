#include <iostream>
#include <string>
#include "Interpreter.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Incorrect usage!\n";
		std::cerr << "Use: " << argv[0] << " code.bf\n";
		return 1;
	}

	ebfi::Interpreter interpreter;
	
	std::string filename = argv[1];

	if (!interpreter.loadCodeFromFile(filename))
	{
		std::cerr << "File " << argv[1] << " doesn\'t exist";
		return 2;
	}
	
	interpreter.executeCode();
}
