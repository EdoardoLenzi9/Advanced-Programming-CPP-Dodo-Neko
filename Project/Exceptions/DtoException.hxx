#ifndef DTO_EXCEPTION_HPP
#define DTO_EXCEPTION_HPP

#include <string>
#include "Const.hxx"

using namespace std;

class DtoException : std::exception{

    public:
        DtoException(Code c, string d): code(c), description(d) {}

        virtual const char * what ( ) const throw () {
            return description.c_str();
        }

        Code getCode(){ return code; }
        string getDescription(){ return description; }

    private:
        Code code;
        string description;

};

#endif