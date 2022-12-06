//
//  Advent of Code 2022 Tests: Day 6
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/05/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(Y2022_SolveDay6, FinalSolutionPartA) {
    EXPECT_EQ("1804", solvea());
}

TEST(Y2022_SolveDay6, FinalSolutionPartB) {
    EXPECT_EQ("2508", solveb());
}

TEST(Y2022_Day6Example,Test1) {
    string x{"mjqjpqmgbljsphdztnvjfqwrcgsmlb"};
    EXPECT_EQ(7,findStartOfSequence(x,4));
    x = "bvwbjplbgvbhsrlpgdmjqwftvncz";
    EXPECT_EQ(5,findStartOfSequence(x,4));
    x = "nppdvjthqldpwncqszvftbrmjlhg";
    EXPECT_EQ(6,findStartOfSequence(x,4));
    x = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
    EXPECT_EQ(10,findStartOfSequence(x,4));
    x = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";
    EXPECT_EQ(11,findStartOfSequence(x,4));
}

TEST(Y2022_Day6Example,Test2) {
    string x{"mjqjpqmgbljsphdztnvjfqwrcgsmlb"};
    EXPECT_EQ(19,findStartOfSequence(x,14));
    x = "bvwbjplbgvbhsrlpgdmjqwftvncz";
    EXPECT_EQ(23,findStartOfSequence(x,14));
    x = "nppdvjthqldpwncqszvftbrmjlhg";
    EXPECT_EQ(23,findStartOfSequence(x,14));
    x = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
    EXPECT_EQ(29,findStartOfSequence(x,14));
    x = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";
    EXPECT_EQ(26,findStartOfSequence(x,14));
}
