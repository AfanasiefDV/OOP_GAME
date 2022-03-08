#include "MyException.h"
MyException::MyException(const ExceptionsNames& inputed_ex_name)
{
    switch (inputed_ex_name)
    {
    case ExceptionsNames::ex_logic_error:
        this->ex_message = "Logic Error";
        break;
    case ExceptionsNames::ex_syntax_error:
        this->ex_message = "Syntax Error";
        break;
    case ExceptionsNames::ex_load_error:
        this->ex_message = "Error load file game";
        break;
        
    }
}

std::ostream& operator<<(std::ostream& out, const MyException& obj)
{
    out << obj.ex_message;
    return out;
}