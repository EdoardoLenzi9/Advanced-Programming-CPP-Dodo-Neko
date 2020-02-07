#ifndef CONST_HPP
#define CONST_HPP

#include <string>

using namespace std;


enum Code { 
    Unauthorized, 
    WrongPassword,
    EmptyList 
};

const string UNAUTHORIZED = "Unauthorized";
const string WRONG_PASSWORD = "Wrong password!";
const string EMPTY_LIST = "No avaliable rooms";

#endif