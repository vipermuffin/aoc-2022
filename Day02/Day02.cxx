//
//  Advent of Code 2022 Solutions: Day 2
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/01/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_map>



using namespace std;
namespace AocDay02 {

    static const std::string InputFileName = "Day02.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int32_t sum = 0;
        for(const auto& round : input) {
            sum += calculateScore(round[0], round[2]);
        }
		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int32_t sum = 0;
        for(const auto& round : input) {
            sum += calculateScore(round[0], round[2], true);
        }
        return to_string(sum);
    }
    const unordered_map<char, int_fast8_t> scoreGuidePartA {
        {'X',1}, //ROCK
        {'Y',2}, //Paper
        {'Z',3}, //Scissors
    };
    const unordered_map<char, int_fast8_t> scoreGuidePartB {
        {'X',0}, //ROCK
        {'Y',3}, //Paper
        {'Z',6}, //Scissors
    };
    
    const unordered_map<char, unordered_map<char, int_fast8_t>> winGuidePartA {
        {'X',{{'A',3},{'B',0},{'C',6}}}, //ROCK
        {'Y',{{'A',6},{'B',3},{'C',0}}}, //Paper
        {'Z',{{'A',0},{'B',6},{'C',3}}}  //Scissors
    };
    const unordered_map<char, unordered_map<char, int_fast8_t>> winGuidePartB {
        {'X',{{'A',3},{'B',1},{'C',2}}}, //ROCK
        {'Y',{{'A',1},{'B',2},{'C',3}}}, //Paper
        {'Z',{{'A',2},{'B',3},{'C',1}}}  //Scissors
    };
    
    int_fast8_t calculateScore(const char a, const char b, bool partB) {
        const auto& scoreGuide = partB ? scoreGuidePartB : scoreGuidePartA;
        const auto& winGuide = partB ? winGuidePartB : winGuidePartA;
        int_fast8_t score{0};
        score = scoreGuide.at(b);
        score += winGuide.at(b).at(a);
        return score;
    }

}
