#include <iostream>

using namespace std;

int main(){

	int x = 0;

	//this points to a location containing an integer
	int *y;

	//y = x; //this is invalid. x is an int, y is a pointer to int. y is supposed to store a memory address, not an int."
	
	cout<<"x contains: "<<x<<"\n";
	cout<<"the address of x:"<<&x<<"\n";
	cout<<"y contains: "<<y<<"\n";

	y = &x; //y now contains the address of x

	x=3;

	cout<<"address at which the pointer resides: "<<&y<<"\n";
	cout<<"actual Value of the pointer variable: "<<y<<"\n";

	cout<<"dereferenced y: "<<*y<<"\n";
}
