//
//  Advent of Code 2022 Tests: Day 17
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay17{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay17;

TEST(Y2022_SolveDay17, FinalSolutionPartA) {
    EXPECT_EQ("3184", solvea());
}

TEST(Y2022_SolveDay17, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2022_Day17Example,Test1) {
    VerticalChamber vc{">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>"};
    
    EXPECT_EQ(1,vc.addRock('-'));
//    vc.printChamber();
    EXPECT_EQ(4,vc.addRock('+'));
//    vc.printChamber();
    EXPECT_EQ(6,vc.addRock('J'));
//    vc.printChamber();
    EXPECT_EQ(7,vc.addRock('l'));
    EXPECT_EQ(9,vc.addRock('o'));
    EXPECT_EQ(10,vc.addRock('-'));
    EXPECT_EQ(13,vc.addRock('+'));
    EXPECT_EQ(15,vc.addRock('J'));
    EXPECT_EQ(17,vc.addRock('l'));
    EXPECT_EQ(17,vc.addRock('o'));
//    vc.printChamber();
}

TEST(Y2022_Day17Example,Test2) {
    string jetstream{">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>"};
    EXPECT_EQ(3068,modelRockHeight(jetstream, 2022));
}

TEST(Y2022_Day17Example,Test3) {
    string jetstream{">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>"};
    EXPECT_EQ(1514285714288,modelRockHeight(jetstream, 1000000000000));
}
