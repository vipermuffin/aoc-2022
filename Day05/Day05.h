//
//  Advent of Code 2022 Solutions: Day 5
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/04/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay05 {
//Function Definitions
    std::vector<std::vector<char>> parseStacksFromInput(const std::vector<std::string>&);
    std::string getfinalOuput(const std::vector<std::string>&, bool canMoveFullStack = false);

}
