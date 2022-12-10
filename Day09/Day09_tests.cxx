//
//  Advent of Code 2022 Tests: Day 9
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/08/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(Y2022_SolveDay9, FinalSolutionPartA) {
    EXPECT_EQ("6642", solvea());
}

TEST(Y2022_SolveDay9, FinalSolutionPartB) {
    EXPECT_EQ("2765", solveb());
}

TEST(Y2022_Day9Example,Test1) {
    vector<string> moves {
        "R 4",
        "U 4",
        "L 3",
        "D 1",
        "R 4",
        "D 1",
        "L 5",
        "R 2"
    };
    unordered_map<uint64_t, int32_t> tailVisited{{0,1}};
    simulateMotion(tailVisited, moves,2);
    EXPECT_EQ(13,tailVisited.size());
}

TEST(Y2022_Day9Example,Test2) {
    vector<string> moves {
        "R 4",
        "U 4",
        "L 3",
        "D 1",
        "R 4",
        "D 1",
        "L 5",
        "R 2"
    };
    unordered_map<uint64_t, int32_t> tailVisited{{0,1}};
    simulateMotion(tailVisited, moves,10);
    EXPECT_EQ(1,tailVisited.size());
}

TEST(Y2022_Day9Example,Test3) {
    vector<string> moves {
        "R 5",
        "U 8",
        "L 8",
        "D 3",
        "R 17",
        "D 10",
        "L 25",
        "U 20"
    };
    unordered_map<uint64_t, int32_t> tailVisited{{0,1}};
    simulateMotion(tailVisited, moves,10);
    EXPECT_EQ(36,tailVisited.size());
}
