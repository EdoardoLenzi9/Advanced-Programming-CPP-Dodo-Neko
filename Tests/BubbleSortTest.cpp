#include <gtest/gtest.h>

#include "TestFixture.hpp"
#include "../Utils/SortingAlgorithms/BubbleSort.hpp"


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