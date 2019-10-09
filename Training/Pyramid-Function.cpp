#include <iostream>

using namespace std;

void pyramid(int length, const char *ch){

	for (int i = 1; i<=length; i+=2){
		for (int j = 0; j<(length-i)/2;j++){
			cout<<" ";
		}
		for (int j = 0; j<i; j++){
			cout<<ch;
		}
		cout<<"\n";
	}



}

int main()
{
	// not entirely sure why unicode symbols have to be a pointer...
	const char *x = u8"\ua668";
	int length;

	cout<<"Enter a pyramid width: ";
	cin>>length;

	if (length > 0){
		pyramid(length, x);
	} else {
		cout<<"Nope.";
	}
}
