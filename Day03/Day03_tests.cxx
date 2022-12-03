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
    auto y = splitStrInHalf(x);
    EXPECT_EQ('p',findCommonLetter(y));
    x = "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL";
    y = splitStrInHalf(x);
    EXPECT_EQ('L',findCommonLetter(y));
    x = "PmmdzqPrVvPwwTWBwg";
    y = splitStrInHalf(x);
    EXPECT_EQ('P',findCommonLetter(y));
    x = "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn";
    y = splitStrInHalf(x);
    EXPECT_EQ('v',findCommonLetter(y));
    x = "ttgJtRGJQctTZtZT";
    y = splitStrInHalf(x);
    EXPECT_EQ('t',findCommonLetter(y));
    x = "CrZsJsPPZsGzwwsLwLmpwMDw";
    y = splitStrInHalf(x);
    EXPECT_EQ('s',findCommonLetter(y));
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
    vector<string> group{x,y,z};
    EXPECT_EQ('r',findCommonLetter(group));
    string x1{"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn"};
    string y1{"ttgJtRGJQctTZtZT"};
    string z1{"CrZsJsPPZsGzwwsLwLmpwMDw"};
    vector<string> group2{x1,y1,z1};
    EXPECT_EQ('Z',findCommonLetter(group2));
}
