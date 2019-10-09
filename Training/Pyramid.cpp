#include <iostream>

using namespace std;

int main()
{
	// not entirely sure why unicode symbols have to be a pointer...
	const char *x = u8"\ua668";

	const int length = 7;

	for (int i = 1; i<=length; i+=2){
		for (int j = 0; j<(length-i)/2;j++){
			cout<<" ";
		}
		for (int j = 0; j<i; j++){
			cout<<x;
		}
		cout<<"\n";
	}

}
