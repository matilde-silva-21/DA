// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>
#include <iterator>
#include <list>

//fin = original, jake = copy
void copyArray(unsigned int fin[], unsigned int jake[], unsigned int n){
    for(auto i=0; i<n; i++){
        auto val = fin[i];
        jake[i]=val;
    }

}

void resetArray(unsigned int jake[], unsigned int n){
    for(auto i=0; i<n; i++){
        jake[i]=0;
    }
}

int getNumberOfCoins(unsigned int jake[], unsigned int n){
    int count=0;
    for(auto i=0; i<n; i++){
        if(jake[i]!=0) count++;
    }
    return count;
}

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    unsigned int st[n], uc[n];
    copyArray(Stock, st, n);
    copyArray(usedCoins, uc, n);

    unsigned int curBestAnswer[n], curBestSize = UINT16_MAX;

    if(T==0){
        return true;
    }

    else{
        for(int i=0; i<n; i++){
            if(Stock[i]==0 || T<C[i]) {continue;}
            Stock[i]--;
            usedCoins[i]++;
            if(changeMakingBF(C,Stock,n,T-C[i], usedCoins)){
                int size = getNumberOfCoins(usedCoins,n);
                if(size<curBestSize){
                    copyArray(usedCoins, curBestAnswer,n);
                    curBestSize=size;
                }
            }
            copyArray(st, Stock, n);
            copyArray(uc, usedCoins, n);
        }
    }

    if(curBestSize!=UINT16_MAX) { copyArray(curBestAnswer,usedCoins,n); return true;}
    else return false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[] = {0,0,0,0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    resetArray(usedCoins, n);
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
    unsigned int usedCoins[]={0,0,0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    resetArray(usedCoins, n);
    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[]={0,0,0,0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    resetArray(usedCoins,n);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}