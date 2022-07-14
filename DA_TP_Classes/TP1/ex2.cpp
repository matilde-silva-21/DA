// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int lastMax = 0, curSum = 0;

    for(int a=0; a<n; a++){
        for(int b=a; b<n;b++){
            curSum+=A[b];
            if(curSum > lastMax){
                lastMax = curSum;
                i = a;
                j = b;
            }
        }
        curSum = 0;
    }

    return lastMax;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}