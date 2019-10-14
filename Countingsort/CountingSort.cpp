#include <iostream>
#include <vector>
#include <random>

using namespace std;

const bool debug = true;

class RandomField{
	public: 

	RandomField(int n, int max){
		data.resize(n, 0);
		this->max = max;
		for (int i=0; i<data.size(); i++){
			data.at(i) = rand()%max;
		}
	}

	void print(){
		for (int i: data){ cout<<i<<" ";}
		cout<<endl;
	}

	int at(int n){
		return data.at(n);
	}

	int getSize(){
		return data.size();
	}
	private:
		vector<int> data;
		int max;
};


int main(){

	srand(time(0)); // bad randomness. good enough for this though. this seed changes once every second.

	int amount = 1000; // amount of unique values in the random field
	int max = 5000; // size of the field

	// generate the random field, basically nothing else than a vector filled with random values.
	RandomField input(amount, max);
	cout<<"Generated a random vector with the following contents: "<<endl;
	input.print(); // output this field

	// the vector that will hold the count of each unique value
	vector<int> count;
	count.resize(max, 0); // make the count tracker the maximum expected number to sort

	// the output, which will be a sorted version of input vector
	vector<int> output;
	output.resize(amount,0);

	// first, look through all of the input array input and increase the value of count at the position of the value of input for every element that appears for that value.
	// i.e. if there's 4x the occurance of value 2, increase count.at(2) 2 times.
	// in the end, the count vector will contain how often each value has appeared in the original vector.
	// the size of this vector must be as big as every unique value of the input array.
	for (int i=0; i<input.getSize(); i++){
		count.at(input.at(i))++; //increase the count of that element at the position in count depending on its value
	}

	// next, sum up how often each element appears. this gives us an idea about until what address in the output vector we will see which element.
	for (int i=1; i<count.size(); i++){
		count.at(i) += count.at(i-1);
	}	
	
	// finally, for every element of the output vector, determine the right element from the input vector. 
	// go through elements of that input vector and determine which address its supposed to appear at, by looking at the count vector.
	// after an element has been placed on the address the count vector specified, decrease that amount by one so next time, the address below will be taken.
	for (int i=0; i<output.size(); i++){
		//cout<<"Value: "<<input.at(i)<<endl;
		//cout<<"On Output array space: "<<count.at(input.at(i))-1<<endl;

		output.at(count.at(input.at(i))-1) = input.at(i);
		count.at(input.at(i)) -= 1;
	}

	//print the output vector
	cout<<"Sorted vector: "<<endl;
	for (int i: output){
		cout<<i<<" ";
	}
	cout<<endl;

}

