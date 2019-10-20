using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <bits/stdc++.h> 
#include "Dijkstra.hpp"
#include "Queue.hpp"


Dijkstra::Dijkstra( string graphDeclaration ) {
    ifstream in(graphDeclaration);      // dataset with the graph definition
    in >> this->N >> this->M;

    data.resize(N);

    for( int i = 0; i < M; i++ ){       // load each arrow
        int from, to, weight;
        in >> from >> to >> weight;
        data[from].addNeighbor(to, weight);
    }
}


int getMinDist(vector<int> dist, vector<bool> isInQueue){
    int min;
    int u;

    for( int i = 0; i < dist.size(); i++ ){
        if( dist[i] < min && isInQueue[i]){
            min = dist[i];
            u = i;
        }
    }

    return u;
}


vector<int> Dijkstra::dijkstra( int source ) {

    vector<int> dist(N, INT_MAX);               // init node distance as infinite (-1) distance from the source node
    vector<int> prev(N, -1);                    // init undefined previous node
    vector<bool> isInQueue(N, true);            // every node is enqueued
    int queueSize = N;
    int alt;
    dist[source] = 0;        
      
                                                                
    while( queueSize > 0 ) {        
        int u = getMinDist(dist, isInQueue);       // node index with minimum distance 
        isInQueue[u] = false;
        queueSize--;

        if( dist[u] == INT_MAX){
            break ;
        }

        for( Edge v : data[ u ].getNeighbors() ){
            if( isInQueue[ v.getNode() ] ){
                alt = dist[ u ] + v.getWeight() ;
            } else {
                break;
            }
            
            if( alt < dist[ v.getNode() ] ){                                 
                dist[ v.getNode() ] = alt ;       // update distance
                prev[ v.getNode() ] = u ;         // update previous node
                //decrease-key v in Q;                           // Riordina v nella coda
            }
        }
    }     
    return dist;
}