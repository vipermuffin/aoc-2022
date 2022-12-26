//
//  Advent of Code 2022 Tests: Day 25
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/25/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay25{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay25;

TEST(Y2022_SolveDay25, FinalSolutionPartA) {
    EXPECT_EQ("2-2=21=0021=-02-1=-0", solvea());
}

TEST(Y2022_SolveDay25, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2022_Day25Example,Test1) {
    EXPECT_EQ(encodeSnafuNumber(    1    ),          "1");
    EXPECT_EQ(encodeSnafuNumber(    2    ),          "2");
    EXPECT_EQ(encodeSnafuNumber(    3    ),          "1=");
    EXPECT_EQ(encodeSnafuNumber(    4    ),          "1-");
    EXPECT_EQ(encodeSnafuNumber(    5    ),          "10");
    EXPECT_EQ(encodeSnafuNumber(    6    ),          "11");
    EXPECT_EQ(encodeSnafuNumber(    7    ),          "12");
    EXPECT_EQ(encodeSnafuNumber(    8    ),          "2=");
    EXPECT_EQ(encodeSnafuNumber(    9    ),          "2-");
    EXPECT_EQ(encodeSnafuNumber(   10    ),          "20");
    EXPECT_EQ(encodeSnafuNumber(   15    ),         "1=0");
    EXPECT_EQ(encodeSnafuNumber(   20    ),         "1-0");
    EXPECT_EQ(encodeSnafuNumber( 2022    ),      "1=11-2");
    EXPECT_EQ(encodeSnafuNumber(12345    ),    "1-0---0");
    EXPECT_EQ(encodeSnafuNumber(314159265),  "1121-1110-1=0");
}

TEST(Y2022_Day25Example,Test2) {
    EXPECT_EQ(decodeSnafuNumber("1=-0-2"),     1747);
    EXPECT_EQ(decodeSnafuNumber("12111"),      906);
    EXPECT_EQ(decodeSnafuNumber("2=0="),      198);
    EXPECT_EQ(decodeSnafuNumber("21"),       11);
    EXPECT_EQ(decodeSnafuNumber("2=01"),      201);
    EXPECT_EQ(decodeSnafuNumber("111"),       31);
    EXPECT_EQ(decodeSnafuNumber("20012"),     1257);
    EXPECT_EQ(decodeSnafuNumber("112"),       32);
    EXPECT_EQ(decodeSnafuNumber("1=-1="),      353);
    EXPECT_EQ(decodeSnafuNumber("1-12"),      107);
    EXPECT_EQ(decodeSnafuNumber("12"),        7);
    EXPECT_EQ(decodeSnafuNumber("1="),        3);
    EXPECT_EQ(decodeSnafuNumber("122"),       37);
}

TEST(Y2022_Day25Example,Test3) {
    vector<string> vals {
        "1=-0-2",
        "12111",
        "2=0=",
        "21",
        "2=01",
        "111",
        "20012",
        "112",
        "1=-1=",
        "1-12",
        "12",
        "1=",
        "122"
    };
    EXPECT_EQ(4890,sumSnafuList(vals));
}
