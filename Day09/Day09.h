//
//  Advent of Code 2022 Solutions: Day 9
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/08/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay09 {
//Function Definitions
void simulateMotion(std::unordered_map<uint64_t,int32_t>& visited, const std::vector<std::string>& moves, const int numKnots);
}
