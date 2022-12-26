//
//  Advent of Code 2022 Solutions: Day 25
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/25/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay25 {
//Function Definitions
int64_t decodeSnafuNumber(const std::string&);
std::string encodeSnafuNumber(const int64_t);
int64_t sumSnafuList(const std::vector<std::string>&);
}
