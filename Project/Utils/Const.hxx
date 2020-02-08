#ifndef CONST_HPP
#define CONST_HPP

#include <string>

using namespace std;


enum Code { 
    Ok = 200,
    Unauthorized = 401,
    NotAcceptable = 406,
    InternalServerError = 501,
};


static map<string, string> CodeLabels = {
    {to_string(Code::Ok), "OK"},
    {to_string(Code::Unauthorized), "Unauthorized"},
    {to_string(Code::NotAcceptable), "Not Acceptable"},
    {to_string(Code::InternalServerError), "Internal Server Error"}
};


const string OK = "Ok";
const string UNAUTHORIZED = "Unauthorized";
const string WRONG_PASSWORD = "Wrong password!";
const string EMPTY_LIST = "No avaliable rooms";
const string NOT_IMPLEMENTED = "Not Implemented";
const string SERVER_ERROR = "Internal Server Error";
const string PAID = "Booking paid and not editable";

#endif