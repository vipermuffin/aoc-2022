//
//  Advent of Code 2022 Tests: Day 15
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/15/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay15{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay15;

TEST(Y2022_SolveDay15, FinalSolutionPartA) {
    EXPECT_EQ("5335787", solvea());
}

TEST(Y2022_SolveDay15, FinalSolutionPartB) {
    EXPECT_EQ("13673971349056", solveb());
}

TEST(Y2022_Day15Example,Test1) {
    vector<string> input{
        "Sensor at x=2, y=18: closest beacon is at x=-2, y=15",
        "Sensor at x=9, y=16: closest beacon is at x=10, y=16",
        "Sensor at x=13, y=2: closest beacon is at x=15, y=3",
        "Sensor at x=12, y=14: closest beacon is at x=10, y=16",
        "Sensor at x=10, y=20: closest beacon is at x=10, y=16",
        "Sensor at x=14, y=17: closest beacon is at x=10, y=16",
        "Sensor at x=8, y=7: closest beacon is at x=2, y=10",
        "Sensor at x=2, y=0: closest beacon is at x=2, y=10",
        "Sensor at x=0, y=11: closest beacon is at x=2, y=10",
        "Sensor at x=20, y=14: closest beacon is at x=25, y=17",
        "Sensor at x=17, y=20: closest beacon is at x=21, y=22",
        "Sensor at x=16, y=7: closest beacon is at x=15, y=3",
        "Sensor at x=14, y=3: closest beacon is at x=15, y=3",
        "Sensor at x=20, y=1: closest beacon is at x=15, y=3"
    };
    auto dict = getBeaconMap(input);
    EXPECT_EQ(14,dict.size());
    Coord testVal{0};
    testVal.xy[xIdx] = 2;
    testVal.xy[yIdx] = 18;
    auto testIdx = testVal.all;
    testVal.xy[xIdx] = -2;
    testVal.xy[yIdx] = 15;
    EXPECT_EQ(testVal.all, dict[testIdx]);
}

TEST(Y2022_Day15Example,Test2) {
    vector<string> input{
        "Sensor at x=2, y=18: closest beacon is at x=-2, y=15",
        "Sensor at x=9, y=16: closest beacon is at x=10, y=16",
        "Sensor at x=13, y=2: closest beacon is at x=15, y=3",
        "Sensor at x=12, y=14: closest beacon is at x=10, y=16",
        "Sensor at x=10, y=20: closest beacon is at x=10, y=16",
        "Sensor at x=14, y=17: closest beacon is at x=10, y=16",
        "Sensor at x=8, y=7: closest beacon is at x=2, y=10",
        "Sensor at x=2, y=0: closest beacon is at x=2, y=10",
        "Sensor at x=0, y=11: closest beacon is at x=2, y=10",
        "Sensor at x=20, y=14: closest beacon is at x=25, y=17",
        "Sensor at x=17, y=20: closest beacon is at x=21, y=22",
        "Sensor at x=16, y=7: closest beacon is at x=15, y=3",
        "Sensor at x=14, y=3: closest beacon is at x=15, y=3",
        "Sensor at x=20, y=1: closest beacon is at x=15, y=3"
    };
    auto dict = getBeaconMap(input);
    EXPECT_EQ(26,countImpossibleSpotsForRow(dict, 10));
}

TEST(Y2022_Day15Example,Test3) {
    vector<string> input{
        "Sensor at x=2, y=18: closest beacon is at x=-2, y=15",
        "Sensor at x=9, y=16: closest beacon is at x=10, y=16",
        "Sensor at x=13, y=2: closest beacon is at x=15, y=3",
        "Sensor at x=12, y=14: closest beacon is at x=10, y=16",
        "Sensor at x=10, y=20: closest beacon is at x=10, y=16",
        "Sensor at x=14, y=17: closest beacon is at x=10, y=16",
        "Sensor at x=8, y=7: closest beacon is at x=2, y=10",
        "Sensor at x=2, y=0: closest beacon is at x=2, y=10",
        "Sensor at x=0, y=11: closest beacon is at x=2, y=10",
        "Sensor at x=20, y=14: closest beacon is at x=25, y=17",
        "Sensor at x=17, y=20: closest beacon is at x=21, y=22",
        "Sensor at x=16, y=7: closest beacon is at x=15, y=3",
        "Sensor at x=14, y=3: closest beacon is at x=15, y=3",
        "Sensor at x=20, y=1: closest beacon is at x=15, y=3"
    };
    auto dict = getBeaconMap(input);
    EXPECT_EQ(56000011,findDistressedBeacon(dict,20));
}

