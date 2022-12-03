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
            x.push_back(findCommonLetter(line));
        }
		return to_string(calcPriority(x));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<char> x{};
        x.reserve(input.size());
        auto itr = input.begin();
        while(itr < input.end()) {
            x.push_back(findCommonBadge(*itr, *(itr+1), *(itr+2)));
            std::advance(itr, 3);
        };
        return to_string(calcPriority(x));
    }

    char findCommonLetter(const std::string& line) {
        string h1{line.begin(),line.begin()+line.size()/2};
        string h2{line.begin()+line.size()/2,line.end()};
        
        for(const char c : h1) {
            if(h2.find(c) != std::string::npos) {
                return c;
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
    
    char findCommonBadge(const std::string& s1, const std::string& s2, const std::string& s3) {
        unordered_map<char, uint_fast8_t> charMap{};
        const vector<string> s{s1,s2,s3};
        for(uint_fast8_t i = 0; i < 3; i++) {
            for(const char c : s[i]) {
                charMap[c] |= (1u << i);
            }
        }
        for(const auto kvp : charMap) {
            if(kvp.second == 7) {
                return kvp.first;
            }
        }
        return '-';
    }
}
