#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <vector>

using namespace std;

class SelectionSort {
public:
	template <typename T>
	void sort(vector<T> &vec)
	{
		int min, posMin;
		for (int i = 0; i < vec.size() - 1; i++) {
			posMin = i;
			for (int j = i + 1; j < vec.size(); j++) {
				if (vec.at(j) < vec.at(posMin)) {
					posMin = j;
				}
			}
			if (posMin != i) {
				std::swap(vec[i], vec[posMin]);
			}
		}
	};
};

#endif
