// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

unsigned int findEarliestFinish(std::vector<Activity> A){
    unsigned int curMin=A[0].finish, curIndex=0;
    for(int i=0; i<A.size(); i++){
        if(curMin>A[i].finish){
            curMin=A[i].finish;
            curIndex=i;
        }
    }
    return curIndex;
}

bool scheduleConflict(std::vector<Activity> A, Activity act){
    for(auto i: A){
        if(act.start>i.start && act.finish<i.finish){return false;}
    }
}
std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {
    std::vector<Activity> res;

    while(res.empty()){
        unsigned int index = findEarliestFinish(A);
        res.push_back(A[index]);
    }


    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}