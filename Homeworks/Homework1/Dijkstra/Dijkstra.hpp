/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <string>


using namespace std;


namespace dijkstra_ns {

    class Edge {
        protected:
            int weight;
            int node;

        public:
            Edge( int node, int weight) : node(node), weight(weight){ };

            // Getters and setters
            int getNode() { return node; }
            int getWeight() { return weight; }
    };


    class Node {
        protected:
            vector<Edge> neighbors;     // list of neighbor nodes
            int distance;               // distance from the source node
            int previous;               // previous node index

        public:
            Node( ) { };

            // Getters and setters
            void setDist( int distance ) { this->distance = distance; }
            void setPrev( int previous ) { this->previous = previous; }
            int getDist( void ) { return this->distance; }
            int getPrev( void ) { return this->previous; }
            vector<Edge> getNeighbors() { return neighbors; }
            void addNeighbor( int node, int weight ) { neighbors.push_back( Edge( node, weight ) ); }
            void setNeighbors( vector<Edge> neighbors ) { this->neighbors = neighbors; }
    };


    class Dijkstra {
        protected:
            int N;  // number of nodes 
            int M;  // number of arrows
            vector< Node > data;	

        public:
            Dijkstra( string graphDeclaration );

            vector<int> dijkstra( int source );
    };

}

#endif