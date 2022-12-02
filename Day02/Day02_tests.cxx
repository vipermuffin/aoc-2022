//
//  Advent of Code 2022 Tests: Day 2
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/01/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(Y2022_SolveDay2, FinalSolutionPartA) {
    EXPECT_EQ("12679", solvea());
}

TEST(Y2022_SolveDay2, FinalSolutionPartB) {
    EXPECT_EQ("14470", solveb());
}

TEST(Y2022_Day2Example,Test1) {
    std::vector<string> guide {
        "A Y",
        "B X",
        "C Z"
    };
    EXPECT_EQ(8,calculateScore(guide[0][0], guide[0][2]));
    EXPECT_EQ(1,calculateScore(guide[1][0], guide[1][2]));
    EXPECT_EQ(6,calculateScore(guide[2][0], guide[2][2]));
}

TEST(Y2022_Day2Example,Test2) {
    std::vector<string> guide {
        "A Y",
        "B X",
        "C Z"
    };
    EXPECT_EQ(4,calculateScore(guide[0][0], guide[0][2], true));
    EXPECT_EQ(1,calculateScore(guide[1][0], guide[1][2], true));
    EXPECT_EQ(7,calculateScore(guide[2][0], guide[2][2], true));
}
