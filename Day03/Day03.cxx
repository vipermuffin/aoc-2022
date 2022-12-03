//
//  Advent of Code 2022 Solutions: Day 3
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/02/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_map>


using namespace std;
namespace AocDay03 {

    static const std::string InputFileName = "Day03.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<char> x{};
        x.reserve(input.size());
        for(const auto& line : input) {
            auto strs = splitStrInHalf(line);
            x.push_back(findCommonLetter(strs));
        }
		return to_string(calcPriority(x));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<char> x{};
        x.reserve(input.size());
        auto itr = input.begin();
        while(itr < input.end()) {
            vector<string> strs{string(*itr),string(*(itr+1)),string(*(itr+2))};
            x.push_back(findCommonLetter(strs));
            std::advance(itr, 3);
        };
        return to_string(calcPriority(x));
    }
    
    std::vector<string> splitStrInHalf(const std::string& s) {
        vector<string> y{
            string(s.begin(),s.begin()+s.size()/2),
            string(s.begin()+s.size()/2,s.end())
        };
        return y;
    }
    
    char findCommonLetter(const std::vector<std::string>&s) {
        unordered_map<char, uint_fast32_t> charMap{};
        uint_fast32_t bitmask = 0;
        for(uint_fast32_t i = 0; i < s.size(); i++) {
            bitmask |= (1u << i);
            for(const char c : s[i]) {
                charMap[c] |= (1u << i);
            }
        }
        for(const auto kvp : charMap) {
            if(kvp.second == bitmask) {
                return kvp.first;
            }
        }
        return '-';
    }
    
    uint32_t calcPriority(const std::vector<char>& chars) {
        uint32_t sum{0};
        for(const char c : chars) {
            if(c >= 'a' && c<= 'z') {
                sum += static_cast<uint32_t>(c-'a')+1;
            } else {
                sum += static_cast<uint32_t>(c-'A')+27;
            }
        }
        return sum;
    }
}
