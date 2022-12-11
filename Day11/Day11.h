//
//  Advent of Code 2022 Solutions: Day 11
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/10/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay11 {
//Function Definitions

struct Monkey {
    Monkey() = default;
    ~Monkey() = default;
    std::vector<int64_t> items;
    int64_t worryAdjustment;
    size_t worryOperation;
    int64_t worryTestDivVal;
    size_t trueMonkey;
    size_t falseMonkey;
    int64_t itemsInspected;
};
std::vector<Monkey> initMonkeys(const std::vector<std::string>&);
int64_t processMonkeyBusiness(std::vector<Monkey>&,int32_t numRounds, bool extraWorried = false);
}
