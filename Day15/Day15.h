//
//  Advent of Code 2022 Solutions: Day 15
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/15/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay15 {
//Function Definitions
    constexpr size_t xIdx = 0;
    constexpr size_t yIdx = 1;
    using Coord = union {
        uint64_t all;
        int32_t  xy[2];
    };
    constexpr int32_t X(const Coord& position) {
        return position.xy[xIdx];
    }

    constexpr int32_t Y(const Coord& position) {
        return position.xy[yIdx];
    }

    std::unordered_map<uint64_t, uint64_t> getBeaconMap(const std::vector<std::string>&);
    int32_t countImpossibleSpotsForRow(const std::unordered_map<uint64_t, uint64_t>&,int32_t row);
    uint64_t findDistressedBeacon(const std::unordered_map<uint64_t, uint64_t>&,const int32_t max);
}
