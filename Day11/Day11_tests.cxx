//
//  Advent of Code 2022 Tests: Day 11
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/10/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

vector<Monkey> initTestMonkeys() {
    vector<Monkey> monkeys{};
    Monkey m{};
    m.items.push_back(79);
    m.items.push_back(98);
    m.worryOperation = 0;
    m.worryAdjustment = 19;
    m.worryTestDivVal = 23;
    m.trueMonkey = 2;
    m.falseMonkey = 3;
    monkeys.push_back(m);
    
    m.items.clear();
    m.items.push_back(54);
    m.items.push_back(65);
    m.items.push_back(75);
    m.items.push_back(74);
    m.worryOperation = 1;
    m.worryAdjustment = 6;
    m.worryTestDivVal = 19;
    m.trueMonkey = 2;
    m.falseMonkey = 0;
    monkeys.push_back(m);
    
    m.items.clear();
    m.items.push_back(79);
    m.items.push_back(60);
    m.items.push_back(97);
    m.worryOperation = 2;
    m.worryAdjustment = 0;
    m.worryTestDivVal = 13;
    m.trueMonkey = 1;
    m.falseMonkey = 3;
    monkeys.push_back(m);
    
    m.items.clear();
    m.items.push_back(74);
    m.worryOperation = 1;
    m.worryAdjustment = 3;
    m.worryTestDivVal = 17;
    m.trueMonkey = 0;
    m.falseMonkey = 1;
    monkeys.push_back(m);
    
    return monkeys;
}

TEST(Y2022_SolveDay11, FinalSolutionPartA) {
    EXPECT_EQ("56120", solvea());
}

TEST(Y2022_SolveDay11, FinalSolutionPartB) {
    EXPECT_EQ("24389045529", solveb());
}

TEST(Y2022_Day11Example,Test1) {
    auto monkeys = initTestMonkeys();
    
    EXPECT_EQ(2,monkeys[0].trueMonkey);
    auto result = processMonkeyBusiness(monkeys, 20);
    EXPECT_EQ(10605, result);
}

TEST(Y2022_Day11Example,Test2) {
    auto monkeys = initTestMonkeys();
    
    EXPECT_EQ(2,monkeys[0].trueMonkey);
    auto result = processMonkeyBusiness(monkeys, 10000, true);
    EXPECT_EQ(2713310158, result);
}

TEST(Y2022_Day11Example,Test3) {
    vector<string> testInput{
        "Monkey 0:",
        "  Starting items: 79, 98",
        "  Operation: new = old * 19",
        "  Test: divisible by 23",
        "    If true: throw to monkey 2",
        "    If false: throw to monkey 3",
        "",
        "Monkey 1:",
        "  Starting items: 54, 65, 75, 74",
        "  Operation: new = old + 6",
        "  Test: divisible by 19",
        "    If true: throw to monkey 2",
        "    If false: throw to monkey 0",
        "",
        "Monkey 2:",
        "  Starting items: 79, 60, 97",
        "  Operation: new = old * old",
        "  Test: divisible by 13",
        "    If true: throw to monkey 1",
        "    If false: throw to monkey 3",
        "",
        "Monkey 3:",
        "  Starting items: 74",
        "  Operation: new = old + 3",
        "  Test: divisible by 17",
        "    If true: throw to monkey 0",
        "    If false: throw to monkey 1",
    };
    auto monkeysFromString = initMonkeys(testInput);
    auto monkeys = initTestMonkeys();
    
    ASSERT_EQ(monkeys.size(), monkeysFromString.size());
    for(int i = 0; i < monkeys.size(); i++) {
        ASSERT_EQ(monkeys[i].items.size(),monkeysFromString[i].items.size());
        for(int j = 0; j < monkeys[i].items.size(); j++) {
            EXPECT_EQ(monkeys[i].items[j], monkeysFromString[i].items[j]);
        }
        EXPECT_EQ(monkeys[i].worryOperation, monkeysFromString[i].worryOperation);
        EXPECT_EQ(monkeys[i].worryAdjustment, monkeysFromString[i].worryAdjustment);
        EXPECT_EQ(monkeys[i].worryTestDivVal, monkeysFromString[i].worryTestDivVal);
        EXPECT_EQ(monkeys[i].trueMonkey, monkeysFromString[i].trueMonkey);
        EXPECT_EQ(monkeys[i].falseMonkey, monkeysFromString[i].falseMonkey);
    }
}
