//
//  Advent of Code 2022 Solutions: Day 6
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/05/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "AoCUtils.h"
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay06 {

    static const std::string InputFileName = "Day06.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findStartOfSequence(input[0], 4));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findStartOfSequence(input[0],14));
    }
    
    int32_t findStartOfSequence(const std::string& line, const int32_t distinctChars) {
        auto itr = line.begin();
        while(itr != line.end()) {
            string tmp{itr,itr+distinctChars};
            std::sort(tmp.begin(), tmp.end());
            auto tItr = std::next(tmp.begin());
            bool repeatFound = false;
            //does not protect against not found and overrunning the line
            while(!repeatFound && tItr != tmp.end()) {
                if(*tItr == *(tItr-1)) {
                    repeatFound = true;
                }
                std::advance(tItr, 1);
            }
            if(repeatFound) {
                std::advance(itr, 1);
            } else {
                std::advance(itr, distinctChars);
                return std::distance(line.begin(), itr);
            }
        }
        
        return -222;
    }
}
