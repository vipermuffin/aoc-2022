//
//  Advent of Code 2022 Solutions: Day 4
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/03/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay04 {

    static const std::string InputFileName = "Day04.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int32_t sum{0};
        for(const auto& line : input) {
            sum += containsRange(line) ? 1 : 0;
        }

		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int32_t sum{0};
        for(const auto& line : input) {
            sum += rangeOverlaps(line) ? 1 : 0;
        }
        
        return to_string(sum);
    }

    bool containsRange(const std::string& pairStr) {
        int32_t r[4];
        sscanf(pairStr.c_str(),"%d-%d,%d-%d", &r[0],&r[1],&r[2],&r[3]);
        if((r[0] <= r[2] && r[1] >= r[3]) ||
           (r[2] <= r[0] && r[3] >= r[1])) {
            return true;
        }
        return false;
        
    }
    bool rangeOverlaps(const std::string& pairStr) {
        int32_t r[4];
        sscanf(pairStr.c_str(),"%d-%d,%d-%d", &r[0],&r[1],&r[2],&r[3]);
        if((r[0] <= r[2] && r[2] <= r[1]) ||
           (r[1] <= r[3] && r[3] <= r[0]) ||
           (r[2] <= r[0] && r[0] <= r[3]) ||
           (r[3] <= r[1] && r[1] <= r[2])
           ) {
            return true;
        }
        return false;
        
    }
}
