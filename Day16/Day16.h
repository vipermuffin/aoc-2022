//
//  Advent of Code 2022 Solutions: Day 16
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay16 {
//Function Definitions
    using TunnelMap = std::unordered_map<std::string,std::pair<int32_t,std::vector<std::string>>>;
    void parseLineForValve(const std::string&,TunnelMap&);
    TunnelMap buildTunnelMapFromInput(const std::vector<std::string>&);
    std::vector<std::string> buildPaths(const TunnelMap&,const int32_t numSteps);
    int32_t calculateTotalPressureRelief(const TunnelMap& tm, const std::vector<std::pair<std::string,bool>>& path);
}
