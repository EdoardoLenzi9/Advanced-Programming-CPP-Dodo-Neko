#ifndef QUEUE_HPP
#define QUEUE_HPP

using namespace std;

#include <vector>
#include <string>

namespace queue{

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
            node<T>* head;
            node<T>* tail;
            // T* index;    // TODO create an index

        public:
            Queue();
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