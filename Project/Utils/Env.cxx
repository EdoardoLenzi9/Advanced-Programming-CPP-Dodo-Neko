#include <Env.hxx>


Env::Env(){
    ifstream i("env.json");
    json j;
    i >> j;

    initSchema = j["initSchema"];
    targetDB = j["targetDB"];
    staticFolder = j["staticFolder"];
    port = j["port"];
}