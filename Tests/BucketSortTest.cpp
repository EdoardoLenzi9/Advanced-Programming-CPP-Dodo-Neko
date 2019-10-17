#include <gtest/gtest.h>
#include "../Utils/SortingAlgorithms/BucketSort.hpp"
#include "../Vector.hpp"


// TODO amazing bug - #ifndef doesn't work as expected
// #include "TestFixture.hpp"


bool lt2 (int a, int b){
    return a < b;
}


TEST(bucketsort, base_test) {
    // Arrange

    int mydata[] = {1,3,2,4,5};
    vector<int> vectorData(mydata, mydata + (sizeof(mydata) / sizeof(mydata[0])));
    NumericVector testVector ( vectorData ); 
    
    ASSERT_FALSE(testVector.isSorted(lt2));

    // Act
    testVector.bucketsort();

    // Assert
    ASSERT_TRUE(testVector.isSorted(lt2));
}

