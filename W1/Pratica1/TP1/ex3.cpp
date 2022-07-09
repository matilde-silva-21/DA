// By: Gonçalo Leão

#include "exercises.h"
#include <iostream>

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    static bool first = true;
    unsigned int currCoins[n];

    for(int i = 0; i < n; i++){
        currCoins[i] = 0;
        if(first)
            usedCoins[i] = UINT32_MAX;
    }

    if(first) first = false;

    for(int i = 0; i < n; i++){
        if(Stock[i] == 0) return false;
        T -= C[i];
        Stock[i]--;
        if(T < 0) return false;
        if (T == 0) {
            currCoins[i]++;
            break;
        }
        if(changeMakingBF(C, Stock, n, T, currCoins))
            currCoins[i]++;
        else {
            T += C[i];
            Stock[i]++;
        }
    }
    if(T > 0) return false;
    else{
        std::cout<<"HELLO\n";
        usedCoins = currCoins;
        for(int i = 0; i < n; i++)
            usedCoins[i] = currCoins[i];
        return true;
        /*long long currCoinCount = 0, usedCoinCount=0;
        for(int i = 0; i < n; i++){
            currCoinCount+=currCoins[i];
            if(usedCoinCount != UINT32_MAX)
                usedCoinCount+=usedCoins[i];
        }
        if(currCoinCount<usedCoinCount) usedCoins = currCoins;*/
    }
    return T == 0;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}