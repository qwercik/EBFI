#ifndef EBFI_INTERPRETER_HPP
#define EBFI_INTERPRETER_HPP

#include <string>

namespace ebfi
{
    class Interpreter
    {
    public:
        Interpreter();
        void setSourceCode(const std::string& source_code);
        void executeCode();

    private:
        std::string source_code;
    };
}

#endif 
