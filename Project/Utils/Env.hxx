/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;


class Env { 
    
    public:
        Env();

        string getTargetDB(){ return targetDB; }
        bool getInitSchema(){ return initSchema; }
        
    private:
        string targetDB;
        bool initSchema;

        string GetEnv(string path);
        
};

#endif