/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <bits/stdc++.h> // INT_MAX
#include "Dijkstra.hpp"
#include "Queue.hpp"


using namespace std;


namespace dijkstra_ns {

    dijkstra_ns::Dijkstra::Dijkstra( string graphDeclaration ) {
        ifstream in(graphDeclaration);      // dataset with the graph definition
        in >> this->N >> this->M;

        data.resize(N);

        for( int i = 0; i < M; i++ ){       // load each arrow
            int from, to, weight;
            in >> from >> to >> weight;
            data[from].addNeighbor(to, weight);
        }
    }


    int getMinDist(vector<int> dist, queue_ns::Queue<int> queue){
        int min;
        int u;

        queue_ns::Node<int>* pivot = queue.head;

        while ( pivot != NULL ){
            if( dist[pivot->data] < min){
                min = dist[pivot->data];
                u = pivot->data;
            }

            pivot = pivot->next;
        }
        return u;
    }


    vector<int> dijkstra_ns::Dijkstra::dijkstra( int source ) {

        vector<int> dist(N, INT_MAX);               // init node distance as infinite (-1) distance from the source node
        vector<int> prev(N, -1);                    // init undefined previous node
        queue_ns::Queue<int> queue;                 // every node is enqueued
        for(int i = 0; i < N; i++){
            queue.enqueue(i);
        }

        dist[source] = 0;        
        int alt;
                                                                    
        while( queue.size() > 0 ) {        
            int u = getMinDist(dist, queue);       // node index with minimum distance 
            queue.dequeue(u);

            if( dist[u] == INT_MAX){
                break ;
            }

            for( Edge v : data[ u ].getNeighbors() ){
                
                alt = dist[ u ] + v.getWeight() ;
                
                if( alt < dist[ v.getNode() ] ){                                 
                    dist[ v.getNode() ] = alt ;       // update distance
                    prev[ v.getNode() ] = u ;         // update previous node
                }
            }
        }     
        return dist;
    }

}