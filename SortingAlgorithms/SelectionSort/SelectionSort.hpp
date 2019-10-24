#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <vector>
#include "../SortingInterface.hpp"
#include "../SortingUtils.hpp"

using namespace std;

class SelectionSort : public SortingInterface {
public:
    template <typename T>
    void sort(vector<T> &vec)
    {
	    cout << "called with a vector" << endl;
		int min, posMin;
		for (int i = 0; i < vec.size()-1; i++){
			//cout << "looking at element " << i << " with value " << vec.at(i) << endl;
			min = vec.at(i);
			posMin = i;
			for (int j = i+1; j < vec.size(); j++){
				//cout << "checking " << vec.at(j) << " < " << vec.at(i) << endl;
				if (vec.at(j) < min){
					min = vec.at(j);
					posMin = j;
					//cout << "new min is now " << vec.at(j) << " at pos " << j << endl;
				}
			}	
			if (posMin != i){
				//cout << "swapping " << vec.at(i) << " with " << vec.at(posMin) << endl;
				std::swap(vec[i], vec[posMin]);
			}
		}
	};

    template <typename T>
    void sort(vector<T> *vec)
    {
	    cout << "called with a pointer" << endl;
		int min, posMin;
		for (int i = 0; i < vec->size()-1; i++){
			//cout << "looking at element " << i << " with value " << vec->at(i) << endl;
			min = vec->at(i);
			posMin = i;
			for (int j = i+1; j < vec->size(); j++){
				//cout << "checking " << vec->at(j) << " < " << vec->at(i) << endl;
				if (vec->at(j) < min){
					min = vec->at(j);
					posMin = j;
					//cout << "new min is now " << vec->at(j) << " at pos " << j << endl;
				}
			}	
			if (posMin != i){
				//cout << "swapping " << vec->at(i) << " with " << vec->at(posMin) << endl;
				std::swap(vec->at(i), vec->at(posMin));
			}
		}
	};
};

#endif
