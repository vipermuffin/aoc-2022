//
//  Advent of Code 2022 Tests: Day 20
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/19/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day20.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay20{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay20;

TEST(Y2022_SolveDay20, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2022_SolveDay20, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2022_Day20Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2022_Day20Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2022_Day20Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
