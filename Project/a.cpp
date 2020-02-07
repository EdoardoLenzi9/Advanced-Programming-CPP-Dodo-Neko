using namespace std;

#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

using json = nlohmann::json;

int main(){
    int a = 200;

    map<string, string> CodeLabels = {
        {to_string(a), "OK"},
        {"201", "Unauthorized"},
        {"202", "Not Acceptable"},
        {"203", "Internal Server Error"}
    };
}