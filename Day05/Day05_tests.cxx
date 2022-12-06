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
    vector<string> x{
        "[D]        ",
        "[N] [C]    ",
        "[Z] [M] [P]",
        " 1   2   3 ",
        "",
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2"
    };
    auto result = parseStacksFromInput(x);
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(3, result[0].size());
    EXPECT_EQ('D',result[0][2]);
    EXPECT_EQ('N',result[0][1]);
    EXPECT_EQ('Z',result[0][0]);
    ASSERT_EQ(2, result[1].size());
    EXPECT_EQ('C',result[1][1]);
    EXPECT_EQ('M',result[1][0]);
    ASSERT_EQ(1, result[2].size());
    EXPECT_EQ('P',result[2][0]);
}

TEST(Y2022_Day5Example,Test2) {
    vector<string> x{
        "    [D]    ",
        "[N] [C]    ",
        "[Z] [M] [P]",
        " 1   2   3 ",
        "",
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2"
    };
    EXPECT_EQ("CMZ",getfinalOuput(x));
}

TEST(Y2022_Day5Example,Test3) {
    vector<string> x{
        "    [D]    ",
        "[N] [C]    ",
        "[Z] [M] [P]",
        " 1   2   3 ",
        "",
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2"
    };
    EXPECT_EQ("MCD",getfinalOuput(x, true));
}
