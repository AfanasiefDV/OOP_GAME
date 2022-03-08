#pragma once
#include <string>
#include <iostream>
enum class ExceptionsNames
{
    ex_logic_error,
    ex_load_error,
    ex_syntax_error,
};

class MyException
{
public:
    MyException(const ExceptionsNames& inputed_ex_name);
    friend std::ostream& operator<<(std::ostream& out, const MyException& obj);
    
private:
    std::string ex_message;
};

