#include <Env.hxx>


Env::Env(){
    ifstream i("env.json");
    json j;
    i >> j;
    initSchema = j["initSchema"];
    targetDB = j["targetDB"];
}