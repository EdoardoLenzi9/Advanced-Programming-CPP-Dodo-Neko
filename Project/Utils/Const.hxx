#ifndef CONST_HPP
#define CONST_HPP

#include <string>

using namespace std;


enum Code { 
    Unauthorized, 
    WrongPassword 
};

const string UNAUTHORIZED = "Unauthorized";
const string WRONG_PASSWORD = "Wrong password!";

#endif