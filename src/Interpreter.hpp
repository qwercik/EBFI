#ifndef EBFI_INTERPRETER_HPP
#define EBFI_INTERPRETER_HPP

#include <string>

namespace ebfi
{
	class Interpreter
	{
	public:
		Interpreter();
		void setCode(const std::string& source_code);
		bool loadCodeFromFile(const std::string& filename);
		void executeCode();

	private:
		std::string source_code;
	};
}

#endif 
