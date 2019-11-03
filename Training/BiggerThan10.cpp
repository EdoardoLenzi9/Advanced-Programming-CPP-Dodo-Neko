#include <iostream>

using namespace std;

int main()
{

	int x = 10;
	int y = 0;

	cout<<"Enter a number: ";
	cin>>y;
	cout<<y<<"\n";
	if (x>y){
		cout<<"The entered number was smaller than 10";
	} else if (x==y) {
		cout<<"The entered number was 10";
	} else {
		cout<<"The entered number was bigger than 10";
	}

	cout<<"\n";

}
