/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>
#include <iostream>
#include <string>


using namespace std;


namespace queue_ns {

    template <typename T>
    class Node;

    template <typename T>
    class Node{
        public:
            T data;
            Node * next;
            Node * previous;
    };


    template <typename T> 
    class Queue
    {
        protected:
            int dim;

        public:
            Node<T>* head;
            Node<T>* tail;
            Queue( void );
            void enqueue( T item );
            T dequeue();
            T dequeue(T item);
            void push( T item );
            T pop( void );
            int size( void ) { return dim; }
            void print(){
                Node<T>* pivot = head;
                while ( pivot != NULL ) {
                    cout << endl << pivot->data;
                    pivot = pivot->next;
                }
            }
    };

}
#endif