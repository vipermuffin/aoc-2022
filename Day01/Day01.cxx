//
//  Advent of Code 2022 Solutions: Day 1
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 11/30/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric>   //std::accumulate



using namespace std;
namespace AocDay01 {

    static const std::string InputFileName = "Day01.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto elves = countAndSortElves(input);
		return to_string(elves.back());
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto elves = countAndSortElves(input);
        return to_string(std::accumulate(elves.rbegin(), elves.rbegin()+3, 0));
    }
    
    std::vector<int32_t> countAndSortElves(const std::vector<std::string>& input) {
        int32_t calories = 0;
        vector<int32_t> elves{};
        for(const auto& num : input) {
            try {
                calories += stoi(num);
            } catch (exception) {
                elves.push_back(calories);
                calories = 0;
            }
        }
        
        std::sort(elves.begin(), elves.end());
        return elves;
    }
}
