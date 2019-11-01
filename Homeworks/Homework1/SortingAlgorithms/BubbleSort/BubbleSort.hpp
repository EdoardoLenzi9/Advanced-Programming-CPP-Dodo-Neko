/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP


#include <vector>


using namespace std;


class BubbleSort {

    public:

        template <typename T>
        void sort(vector<T> &vec)
        {
            for (int n = 0; n < vec.size() - 1; n++)
                for (int k = 0; k < vec.size() - n - 1; k++)
                    if (vec.at(k) > vec.at(k + 1))
                        std::swap(vec[k], vec[k + 1]);
        };

};

#endif // BUBBLESORT_HPP