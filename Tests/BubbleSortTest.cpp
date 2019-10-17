#include <gtest/gtest.h>
#include "../Utils/SortingAlgorithms/BubbleSort.hpp"
#include "TestFixture.hpp"
//bool lt1 (int a, int b){
//    return a < b;
//}

TEST(bubblesort, base_test) {
    // Arrange

    int mydata[] = {1,3,2,4,5};
    vector<int> vectorData(mydata, mydata + (sizeof(mydata) / sizeof(mydata[0])));
    Vector<int> testVector ( vectorData ); 
    
    ASSERT_FALSE(testVector.isSorted(lt));

    // Act
    testVector.bubblesort(lt);

    // Assert
    ASSERT_TRUE(testVector.isSorted(lt));
}