/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include "Dijkstra.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Utils.hpp"


using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> row1{ 1, 3, 1, 9 };
    vector<int> row2{ 1, 1, -1, 1 };
    vector<int> row3{ 3, 11, 5, 35 }; 
    vector<vector<int>> data {row1, row2, row3};

    fill_graph(10000, 50000, 10);
	//dijkstra_ns::Dijkstra test ( "graph.txt" );
    dijkstra_ns::Dijkstra test ( "graphtest.txt" );

    vector<int> res = test.dijkstra(0);
    for(int v : res){
        cout << v ;     // 0392486
    }

    return 0;
}
