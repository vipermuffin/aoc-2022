//
//  Advent of Code 2022 Tests: Day 21
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/21/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(Y2022_SolveDay21, FinalSolutionPartA) {
    EXPECT_EQ("110181395003396", solvea());
}

TEST(Y2022_SolveDay21, FinalSolutionPartB) {
    EXPECT_EQ("3721298272959", solveb());
}

TEST(Y2022_Day21Example,Test1) {
    vector<string> input {
    "root: pppw + sjmn",
    "dbpl: 5",
    "cczh: sllz + lgvd",
    "zczc: 2",
    "ptdq: humn - dvpt",
    "dvpt: 3",
    "lfqf: 4",
    "humn: 5",
    "ljgn: 2",
    "sjmn: drzm * dbpl",
    "sllz: 4",
    "pppw: cczh / lfqf",
    "lgvd: ljgn * ptdq",
    "drzm: hmdt - zczc",
    "hmdt: 32"
    };
    EXPECT_EQ(152,processMonkeyBusiness(input));
}

TEST(Y2022_Day21Example,Test2) {
    vector<string> input {
        "root: pppw + sjmn",
        "dbpl: 5",
        "cczh: sllz + lgvd",
        "zczc: 2",
        "ptdq: humn - dvpt",
        "dvpt: 3",
        "lfqf: 4",
        "humn: 5",
        "ljgn: 2",
        "sjmn: drzm * dbpl",
        "sllz: 4",
        "pppw: cczh / lfqf",
        "lgvd: ljgn * ptdq",
        "drzm: hmdt - zczc",
        "hmdt: 32"
    };
    EXPECT_EQ(301,processMonkeyBusiness2(input));
}

TEST(Y2022_Day21Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
