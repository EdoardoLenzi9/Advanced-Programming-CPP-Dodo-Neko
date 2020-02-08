#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;
using json = nlohmann::json;


int main()
{
    json j;
            j["data"]["rooms"] = { 
                
                                    { { "roomid", 12 }, 
                                   { "features", { { {"id", 13 }, 
                                                   {"name", "asdfasfd"}, 
                                                   {"price", 5.3},
                                                   {"amount", 2} 
                                                 }, { {"id", 13 }, 
                                                   {"name", "asdfasfd"}, 
                                                   {"price", 5.3},
                                                   {"amount", 2} 
                                                 } }
                                    } },
                                    { { "roomid", 12 }, 
                                   { "features", { { {"id", 13 }, 
                                                   {"name", "asdfasfd"}, 
                                                   {"price", 5.3},
                                                   {"amount", 2} 
                                                 }, { {"id", 13 }, 
                                                   {"name", "asdfasfd"}, 
                                                   {"price", 5.3},
                                                   {"amount", 2} 
                                                 } }
                                    } }
                                 };

    json a;
    json room;
    json feature;

    a["data"]["rooms"] = {};

    room["room"] = { "roomid", 1 };
    a["data"]["rooms"].push_back(room["room"]);
    room["room"] = { "roomid", 2 };
    a["data"]["rooms"].push_back(room["room"]);
    
    /*
                feature["feature"] = { { { "id", r.features[0].id }, 
                                         { "name", r.features[0].name }, 
                                         { "price", r.features[0].price },
                                         { "amount", r.features[0].amount } } };*/

    cout << j.dump();
}

