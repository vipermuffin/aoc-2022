//
//  Advent of Code 2022 Solutions: Day 9
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/08/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function


using namespace std;
namespace AocDay09 {

constexpr int X = 0;
constexpr int Y = 1;
using Coord = union {
    uint64_t all;
    int32_t  xy[2];
};

int32_t getMaxCoordDiff(const Coord xy1, const Coord xy2) {
    return std::max(abs(xy1.xy[Y]-xy2.xy[Y]),abs(xy1.xy[X]-xy2.xy[X]));
}

    static const std::string InputFileName = "Day09.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<uint64_t, int32_t> tailVisited{{0,1}};
        simulateMotion(tailVisited, input,2);
		return to_string(tailVisited.size());
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<uint64_t, int32_t> tailVisited{{0,1}};
        simulateMotion(tailVisited, input, 10);
        return to_string(tailVisited.size());
    }

void simulateMotion(std::unordered_map<uint64_t,int32_t>& visited, const std::vector<std::string>& moves, const int numKnots) {
    vector<Coord> knots;
    knots.reserve(numKnots);
    Coord tmp{0};
    for(int i = 0; i < numKnots; i++) {
        knots.push_back(tmp);
    }
    
    unordered_map<string, std::function<void(Coord&)>> ops{
        {"U",[&](Coord& headP){headP.xy[Y]++;}},
        {"D",[&](Coord& headP){headP.xy[Y]--;}},
        {"L",[&](Coord& headP){headP.xy[X]--;}},
        {"R",[&](Coord& headP){headP.xy[X]++;}}
    };
    
    for(const auto& line : moves) {
        auto words = parseLineForWords(line);
        auto repeat = stoi(words[1]);
        for(int i = 0; i < repeat;i++) {
            Coord prevTail{knots.back()};
            auto hItr = knots.begin();
            auto tItr = knots.begin()+1;
            
            ops[words[0]](*hItr);
            while(tItr != knots.end()) {
                if(getMaxCoordDiff(*hItr, *tItr) >= 2) {
                    if(hItr->xy[X] != tItr->xy[X]) {
                        hItr->xy[X] > tItr->xy[X] ? tItr->xy[X]++ : tItr->xy[X]--;
                    }
                    if(hItr->xy[Y] != tItr->xy[Y]) {
                        hItr->xy[Y] > tItr->xy[Y] ? tItr->xy[Y]++ : tItr->xy[Y]--;
                    }
                }
                std::advance(hItr, 1);
                std::advance(tItr, 1);
            }
            
            if(knots.back().all != prevTail.all) {
                visited[knots.back().all]++;
            }
        }
    }
}
}
