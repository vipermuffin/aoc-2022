//
//  Advent of Code 2022 Tests: Day 5
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/04/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay05;

TEST(Y2022_SolveDay5, FinalSolutionPartA) {
    EXPECT_EQ("SPFMVDTZT", solvea());
}

TEST(Y2022_SolveDay5, FinalSolutionPartB) {
    EXPECT_EQ("ZFSJBPRFP", solveb());
}

TEST(Y2022_Day5Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2022_Day5Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2022_Day5Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
