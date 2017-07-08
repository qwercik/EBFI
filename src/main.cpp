#include <iostream>
#include <string>
#include "Interpreter.hpp"

void displayHelp(std::ostream& stream);

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Incorrect usage!\n";
		displayHelp(std::cerr);
		return 1;
	}
	else if (std::string(argv[1]) == "--help")
	{
		displayHelp(std::cout);
		return 0;
	}

	ebfi::Interpreter interpreter;
	
	std::string filename = argv[1];

	if (!interpreter.loadCodeFromFile(filename))
	{
		std::cerr << "File " << argv[1] << " doesn\'t exist\n";
		return 2;
	}
	
	interpreter.executeCode();
}

void displayHelp(std::ostream& stream)
{
	stream << "Use: ./ebfi code.bf\n"; 
}
