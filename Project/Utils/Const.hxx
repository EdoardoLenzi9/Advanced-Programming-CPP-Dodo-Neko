#ifndef CONST_HPP
#define CONST_HPP

#include <string>

using namespace std;


enum Code { 
    Ok,
    Unauthorized, 
    WrongPassword,
    EmptyList 
};

const string OK = "Ok";
const string UNAUTHORIZED = "Unauthorized";
const string WRONG_PASSWORD = "Wrong password!";
const string EMPTY_LIST = "No avaliable rooms";

#endif