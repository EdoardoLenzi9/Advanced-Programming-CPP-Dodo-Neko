/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include <vector>
#include <iostream>

#include "BubbleSort.hpp"
#include "Utils.hpp"


int main(void)
{
    int size = 10000;
    vector<int> vec;

    vec.reserve(size);

    fill_vector(vec, 0, 10000);

    print_vector(vec);
    cout << endl;
    BubbleSort bs;
    bs.sort(vec);
    print_vector(vec);
    cout << endl
         << "Vector is sorted: " << is_sorted(vec) << endl;

    return 0;
}
