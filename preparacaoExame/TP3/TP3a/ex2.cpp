#include "exercises.h"

bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    unsigned int bestChange[T+1];
    int lastChangeIteration[T+1];
    for(int i = 0; i < n; i++){
        usedCoins[i]=0;
    }
    for(int i=0; i<=T; i++){
        bestChange[i]=UINT16_MAX;
        lastChangeIteration[i]=-1;
    }
    for(int curCoinIndex = 0; curCoinIndex < n; curCoinIndex++){
        for(int curChange=C[curCoinIndex]; curChange<=T; curChange++){
            int copyChange=curChange, copyIndex=curCoinIndex, coinCount=0;
            while(copyChange!=0){
                if(copyChange >= C[copyIndex]){
                    int divInteira = (copyChange-(copyChange%C[copyIndex]));
                    copyChange -= divInteira;
                    coinCount+= divInteira/C[copyIndex];
                }
                else copyIndex--;
                if(copyIndex < 0){
                    return false;
                }
            }
            if(coinCount < bestChange[curChange]){
                bestChange[curChange] = coinCount;
                lastChangeIteration[curChange] = curCoinIndex;
            }
        }

    }

    if(lastChangeIteration[T]==-1) return false;

    while(T!=0){
        int coinIndex = lastChangeIteration[T], divInteira = (T-(T%C[coinIndex]));
        T-=divInteira;
        usedCoins[coinIndex]+=divInteira/C[coinIndex];
    }
    return true;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, hasChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 1);
    EXPECT_EQ(usedCoins[3], 3);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,10,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP4_Ex2, hasChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,7,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 2);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);
}

TEST(TP4_Ex2, hasNoChange) {
    unsigned int C[] = {5,10};
    unsigned int n = 2;
    unsigned int usedCoins[2];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,1,usedCoins), false);
}