//
//  Advent of Code 2022 Tests: Day 8
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/07/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(Y2022_SolveDay8, FinalSolutionPartA) {
    EXPECT_EQ("1818", solvea());
}

TEST(Y2022_SolveDay8, FinalSolutionPartB) {
    EXPECT_EQ("368368", solveb());
}

TEST(Y2022_Day8Example,Test1) {
    vector<string> input {
        "30373",
        "25512",
        "65332",
        "33549",
        "35390"
    };
    EXPECT_EQ(21,countVisibleTrees(input));
}

TEST(Y2022_Day8Example,Test2) {
    vector<string> input {
        "30373",
        "25512",
        "65332",
        "33549",
        "35390"
    };
    EXPECT_EQ(8,findHighestScenicVal(input));
}
