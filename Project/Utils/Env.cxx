#include <Env.hxx>


Env::Env(){
    ifstream i("env.json");
    json j;
    i >> j;

    port = j["port"];
    staticFolder = j["staticFolder"];
    targetDB = j["targetDB"];
    backupDB = j["backupDB"];
    initSchema = j["initSchema"];
    initData = j["initData"];
    sessionTime = j["sessionTime"];
    debugMode = j["debugMode"];
}