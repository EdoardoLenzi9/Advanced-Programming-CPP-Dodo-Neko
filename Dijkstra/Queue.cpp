using namespace queue;

#include "Queue.hpp"

template <typename item>
Queue<item>::Queue(){
	dim = 0;
	head = NULL;
	tail = NULL;
}

template <typename T>
void Queue<T>::enqueue(T item){
	Node<item> * tmp = new (nothrow) node<item>; //nothrow avoid out of memory exeptions
	tmp->data = item;
	tmp->next = NULL;
	tmp->previous = tail;
	if(head == NULL)
		head = tmp;
	if(tail != NULL)
		tail->next = tmp;
	tail = tmp;
	dim++;
}

template <typename T>
T Queue<T>::dequeue(){
	if(head != NULL && dim != 0){
		T res = head->data;
		Node<T> * tmp; 
		if(head->next!=NULL){
			tmp = head->next;
			tmp->previous = NULL;
			delete head;
		}
		head = tmp;
		dim--;
		return res;
	}
	cerr<<"ERROR EMPTY QUEUE ";
	return 0;
}


template <typename T>
T Queue<T>::dequeue( T item ){
    Node<T>* pivot = head;

	while(pivot != NULL && dim != 0){

        if(pivot->data == item){
            pivot->previous->next = pivot->next;
            pivot->next->previous = pivot->previous;
            delete pivot;
		    dim--;
            return item;
        }
        pivot = pivot->next;
	}

	cerr<<"ERROR ITEM NOT FOUND ";
	return NULL;
}


template <typename T>
void Queue<T>::push(T i){
	enqueue(i);
}

template <typename T>
T Queue<T>::pop(){
	if(tail != NULL && dim != 0){
		T res = tail->data;
		Node<T> * tmp; 
		if(tail->previous!=NULL){

			tmp = tail->previous;
			tmp->next = NULL;
			delete tail;
		}
		tail = tmp;
		dim--;
		return res;
	}
	cerr<<"ERROR EMPTY STACK ";
	return 0;
}