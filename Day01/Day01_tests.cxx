//
//  Advent of Code 2022 Tests: Day 1
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 11/30/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay01{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay01;

TEST(Y2022_SolveDay1, FinalSolutionPartA) {
    EXPECT_EQ("73211", solvea());
}

TEST(Y2022_SolveDay1, FinalSolutionPartB) {
    EXPECT_EQ("213958", solveb());
}

TEST(Y2022_Day1Example,Test1) {
    vector<string> x{
        "1000",
        "2000",
        "3000",
        "",
        "4000",
        "",
        "5000",
        "6000",
        "",
        "7000",
        "8000",
        "9000",
        "",
        "10000"
    };
    auto elves = countAndSortElves(x);
    
    EXPECT_EQ(4000,elves.front());
    EXPECT_EQ(24000,elves.back());
}

