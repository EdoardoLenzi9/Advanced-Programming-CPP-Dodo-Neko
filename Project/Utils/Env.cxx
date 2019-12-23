#include <Env.hxx>


Env::Env(){
    string env = GetEnv("env.json");
    json j = json::parse(env);
    targetDB = j["targetDB"];
    initSchema = j["initSchema"];
}


string Env::GetEnv(string path){
    ifstream file(path);
    string content;

    while(file >> content) {
        cout << content << ' ';
    }
    return content;
}