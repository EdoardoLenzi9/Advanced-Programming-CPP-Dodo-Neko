#include <gtest/gtest.h>
#include "../Utils/SortingAlgorithms/InsertionSort.hpp"
// TODO amazing bug - #ifndef doesn't work as expected
// #include "TestFixture.hpp"


bool lt3 (int a, int b){
    return a < b;
}

TEST(insertionsort, base_test) {
    // Arrange

    int mydata[] = {1,3,2,4,5};
    vector<int> vectorData(mydata, mydata + (sizeof(mydata) / sizeof(mydata[0])));
    Vector<int> testVector ( vectorData ); 
    
    ASSERT_FALSE(testVector.isSorted(lt3));

    // Act
    testVector.insertionsort(lt3);

    // Assert
    ASSERT_TRUE(testVector.isSorted(lt3));
}