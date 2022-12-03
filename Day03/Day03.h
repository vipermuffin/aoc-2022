//
//  Advent of Code 2022 Solutions: Day 3
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/02/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay03 {
//Function Definitions
    char findCommonLetter(const std::string&);
    uint32_t calcPriority(const std::vector<char>&);
    char findCommonBadge(const std::string&, const std::string&, const std::string&);
}
