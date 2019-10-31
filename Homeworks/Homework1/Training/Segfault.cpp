#include <iostream>

using namespace std; 

int main(){
	int *p;

	cout<<"Dereferenced p: "<<*p<<"\n"; //this should crash with a segfault
}
