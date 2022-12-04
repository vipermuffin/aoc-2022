//
//  Advent of Code 2022 Tests: Day 4
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/03/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(Y2022_SolveDay4, FinalSolutionPartA) {
    EXPECT_EQ("485", solvea());
}

TEST(Y2022_SolveDay4, FinalSolutionPartB) {
    EXPECT_EQ("857", solveb());
}

TEST(Y2022_Day4Example,Test1) {
    string x{"2-8,3-7"};
    EXPECT_TRUE(containsRange(x));
    x = "6-6,4-6";
    EXPECT_TRUE(containsRange(x));
    x = "2-4,6-8";
    EXPECT_FALSE(containsRange(x));
    x = "5-7,7-9";
    EXPECT_FALSE(containsRange(x));
    
}

TEST(Y2022_Day4Example,Test2) {
    string x{"2-4,6-8"};
    EXPECT_FALSE(rangeOverlaps(x));
    x = "2-3,4-5";
    EXPECT_FALSE(rangeOverlaps(x));
    x = "5-7,7-9";
    EXPECT_TRUE(rangeOverlaps(x));
    x = "2-8,3-7";
    EXPECT_TRUE(rangeOverlaps(x));
    x = "6-6,4-6";
    EXPECT_TRUE(rangeOverlaps(x));
    x = "2-6,4-8";
    EXPECT_TRUE(rangeOverlaps(x));
}
