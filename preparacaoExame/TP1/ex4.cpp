// By: Gonçalo Leão

#include "exercises.h"
#include <stack>

bool changeMakingGreedy(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    std::stack<int> saint;
    for(int i=0; i<n; i++){
        usedCoins[i]=0;
        for(int k=0; k<Stock[i]; k++){
            saint.push(i);
        }
    }

    while(!saint.empty()){
        int index = saint.top();
        saint.pop();
        if(T>=C[index]){
            T-=C[index];
            Stock[index]--;
            usedCoins[index]++;
        }
        if(T==0)return true;
    }


    if(T==0)return true;
    return false;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex4, hasGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingGreedy(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex4, hasNoGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingGreedy(C,Stock,n,1,usedCoins), false);
}