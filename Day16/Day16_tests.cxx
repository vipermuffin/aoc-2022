//
//  Advent of Code 2022 Tests: Day 16
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay16{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay16;

TEST(Y2022_SolveDay16, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2022_SolveDay16, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2022_Day16Example,Test1) {
    string x = "Valve AA has flow rate=7; tunnels lead to valves DD, II, BB";
    TunnelMap tm{};
    parseLineForValve(x, tm);
    ASSERT_EQ(1, tm.size());
    ASSERT_EQ(1, tm.count("AA"));
    EXPECT_EQ(7, tm.at("AA").first);
    ASSERT_EQ(3, tm.at("AA").second.size());
    EXPECT_EQ("DD", tm.at("AA").second[0]);
    EXPECT_EQ("II", tm.at("AA").second[1]);
    EXPECT_EQ("BB", tm.at("AA").second[2]);
}

TEST(Y2022_Day16Example,Test2) {
    vector<string> input {
        "Valve AA has flow rate=0; tunnels lead to valves DD, II, BB",
        "Valve BB has flow rate=13; tunnels lead to valves CC, AA",
        "Valve CC has flow rate=2; tunnels lead to valves DD, BB",
        "Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE",
        "Valve EE has flow rate=3; tunnels lead to valves FF, DD",
        "Valve FF has flow rate=0; tunnels lead to valves EE, GG",
        "Valve GG has flow rate=0; tunnels lead to valves FF, HH",
        "Valve HH has flow rate=22; tunnel leads to valve GG",
        "Valve II has flow rate=0; tunnels lead to valves AA, JJ",
        "Valve JJ has flow rate=21; tunnel leads to valve II"
    };
    TunnelMap tm = buildTunnelMapFromInput(input);
    buildPaths(tm, 30);
    EXPECT_EQ(0,0);
}

TEST(Y2022_Day16Example,Test3) {
    vector<string> input {
        "Valve AA has flow rate=0; tunnels lead to valves DD, II, BB",
        "Valve BB has flow rate=13; tunnels lead to valves CC, AA",
        "Valve CC has flow rate=2; tunnels lead to valves DD, BB",
        "Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE",
        "Valve EE has flow rate=3; tunnels lead to valves FF, DD",
        "Valve FF has flow rate=0; tunnels lead to valves EE, GG",
        "Valve GG has flow rate=0; tunnels lead to valves FF, HH",
        "Valve HH has flow rate=22; tunnel leads to valve GG",
        "Valve II has flow rate=0; tunnels lead to valves AA, JJ",
        "Valve JJ has flow rate=21; tunnel leads to valve II"
    };
    TunnelMap tm = buildTunnelMapFromInput(input);
    std::vector<std::pair<string,bool>> path{
        {"AA",false},
        {"DD",true},
        {"CC",false},
        {"BB",true},
        {"AA",false},
        {"II",false},
        {"JJ",true},
        {"II",false},
        {"AA",false},
        {"DD",false},
        {"EE",false},
        {"FF",false},
        {"GG",false},
        {"HH",true},
        {"GG",false},
        {"FF",false},
        {"EE",true},
        {"DD",false},
        {"CC",true},
    };
    EXPECT_EQ(1651,calculateTotalPressureRelief(tm, path));
}
