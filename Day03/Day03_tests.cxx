//
//  Advent of Code 2022 Tests: Day 3
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/02/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(Y2022_SolveDay3, FinalSolutionPartA) {
    EXPECT_EQ("7737", solvea());
}

TEST(Y2022_SolveDay3, FinalSolutionPartB) {
    EXPECT_EQ("2697", solveb());
}

TEST(Y2022_Day3Example,Test1) {
    string x{"vJrwpWtwJgWrhcsFMMfFFhFp"};
    
    EXPECT_EQ('p',findCommonLetter(x));
    x = "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL";
    EXPECT_EQ('L',findCommonLetter(x));
    x = "PmmdzqPrVvPwwTWBwg";
    EXPECT_EQ('P',findCommonLetter(x));
    x = "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn";
    EXPECT_EQ('v',findCommonLetter(x));
    x = "ttgJtRGJQctTZtZT";
    EXPECT_EQ('t',findCommonLetter(x));
    x = "CrZsJsPPZsGzwwsLwLmpwMDw";
    EXPECT_EQ('s',findCommonLetter(x));
}

TEST(Y2022_Day3Example,Test2) {
    vector<char>x{
        'p','L','P','v','t','s'
    };
    EXPECT_EQ(157,calcPriority(x));
}

TEST(Y2022_Day3Example,Test3) {
    string x{"vJrwpWtwJgWrhcsFMMfFFhFp"};
    string y{"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL"};
    string z{"PmmdzqPrVvPwwTWBwg"};
    EXPECT_EQ('r',findCommonBadge(x, y, z));
    string x1{"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn"};
    string y1{"ttgJtRGJQctTZtZT"};
    string z1{"CrZsJsPPZsGzwwsLwLmpwMDw"};
    EXPECT_EQ('Z',findCommonBadge(x1, y1, z1));
}
