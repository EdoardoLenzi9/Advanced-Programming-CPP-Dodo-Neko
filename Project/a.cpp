using namespace std;

#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

using json = nlohmann::json;

int main(){
    
    string content = "{\"auth\":{\"sid\":\"testsid\"},\"data\":{\n\"username\": \"asdfasdf\",\n\"password\":\"asdf\"\n}}";
    json j = json::parse(content);
    cout << j["auth"];
}