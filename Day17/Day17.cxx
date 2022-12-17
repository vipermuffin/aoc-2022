//
//  Advent of Code 2022 Solutions: Day 17
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay17 {

    static const std::string InputFileName = "Day17.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(modelRockHeight(input[0], 2022));
    }

    std::string solveb() {
        //2125906289 too low
        auto input = parseFileForLines(InputFileName);
        
        return to_string(modelRockHeight(input[0], 1000000000000));
//        return to_string(modelRockHeight(input[0], 2022));//1000000000000));
    }
    
    constexpr int X = 0;
    constexpr int Y = 1;
    using Coord = union {
        uint64_t all;
        int32_t  xy[2];
    };
    
    const unordered_map<char, vector<std::pair<int32_t,int32_t>>> rockRelPositions {
        {'-',{{0,0},{1,0},{2,0},{3,0}}},
        {'+',{{1,0},{0,1},{1,2},{2,1}}},
        {'J',{{0,0},{1,0},{2,0},{2,1},{2,2}}},
        {'l',{{0,0},{0,1},{0,2},{0,3}}},
        {'o',{{0,0},{1,0},{0,1},{1,1}}}
    };
    const unordered_map<char, std::pair<int32_t,int32_t>> adjustPos {
        {'<',{-1,0}},
        {'>',{1,0}},
        {'v',{0,-1}}
    };
    
    
    
    VerticalChamber::VerticalChamber(const std::string& windStream) : jetPattern(windStream), chamberRockPoints(), initPosition(), maxHeight(-1), currentJetPatternIdxX2(0), repeatInterval(0), repeated(false) {}
    
    int32_t VerticalChamber::addRock(char rockId) {
        
        //Init position
        Coord tmp{0};
        tmp.xy[X] = 2;
        tmp.xy[Y] = maxHeight+4;
        vector<Coord> currentPos{};
        auto rockRelPos = rockRelPositions.at(rockId);
        currentPos.reserve(rockRelPos.size());
        for(const auto& p : rockRelPos) {
            Coord pos{tmp};
            pos.xy[X] += p.first;
            pos.xy[Y] += p.second;
            currentPos.push_back(pos);
        }
        
        //Apply falling rules
        //Always begin with jet blast
        auto initJetIdx = currentJetPatternIdxX2;
        bool done = false;
        while(!done) {
            //Get movement pattern
            std::pair<int32_t,int32_t> moveBy{};
            bool falling = (currentJetPatternIdxX2 & 1) == 1;
            currentJetPatternIdxX2++;
            if(currentJetPatternIdxX2 == jetPattern.size()*2) {
                currentJetPatternIdxX2 = 0;
            }
            if(falling) {
                //odd, this is falling
                moveBy = adjustPos.at('v');
            } else {
                //push left/right
                auto idx = currentJetPatternIdxX2>>1;
                moveBy = adjustPos.at(jetPattern[idx]);
            }
            //apply movement
            bool moved = true;
            vector<Coord> newPositions{};
            newPositions.reserve(currentPos.size());
            for(auto pos : currentPos) {
                pos.xy[X] += moveBy.first;
                pos.xy[Y] += moveBy.second;
                newPositions.push_back(pos);
                if(chamberRockPoints.count(pos.all) == 1 || pos.xy[X] < 0 || pos.xy[X] > 6 || pos.xy[Y] < 0) {
                    //Either hit chamber limits or another rock
                    moved = false;
                }
            }
            if(moved) {
                std::swap(newPositions,currentPos);
            } else {
                if(falling) {
                    done = true;
                }
            }
        }
        
        //Add new rocks to chamber and find new max height
        auto newMax{-1};
        bool newPosition = initPosition.count(rockId) == 0 || initPosition.at(rockId).count(initJetIdx) == 0;
        bool repeat = true;
        for(auto pos : currentPos) {
            chamberRockPoints[pos.all] = true;
            
            if(pos.xy[Y] > newMax) {
                newMax = pos.xy[Y];
            }
            pos.xy[Y] -= maxHeight > 0 ? maxHeight : 0;
            if(newPosition) {
                initPosition[rockId][initJetIdx][pos.all] = true;
                repeat = false;
            } else {
                if(!initPosition[rockId][initJetIdx][pos.all]) {
                    repeat = false;
                }
            }
        }
        
        if(repeated || repeat) {
            repeated = true;
        } else {
            repeatInterval++;
        }
        
        if(newMax > maxHeight) {
            maxHeight = newMax;
        }
        
        return maxHeight+1;
    }

    void VerticalChamber::printChamber() const {
        for(int_fast32_t i = maxHeight; i >= 0; i--) {
            Coord tmp{0};
            tmp.xy[Y] = i;
            for(int_fast32_t j = 0; j < 7;j++) {
                tmp.xy[X] = j;
                if(chamberRockPoints.count(tmp.all)) {
                    if(chamberRockPoints.at(tmp.all)) {
                        cout << '#';
                    } else {
                        cout << '.';
                    }
                } else {
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
    
    bool VerticalChamber::repeatDetected() const {
        return repeated;
    }
    int32_t VerticalChamber::getRepeatInterval() const {
        return repeatInterval;
    }
    int32_t findRepeatInterval(std::string& jetstream) {
        VerticalChamber vc{jetstream};
        string rockOrder{"-+Jlo"};
        auto itr = rockOrder.begin();
        auto height{0};
        while(!vc.repeatDetected() && vc.getRepeatInterval() >= 0) {
            height = vc.addRock(*itr);
            std::advance(itr, 1);
            if(itr == rockOrder.end()) {
                itr = rockOrder.begin();
            }
        }
        return vc.getRepeatInterval();
    }
    
    int64_t modelRockHeight(std::string& jetstream, const int64_t numRocks) {
        VerticalChamber vc{jetstream};
        string rockOrder{"-+Jlo"};
        auto itr = rockOrder.begin();
        auto height{0};
        auto finalHeight{0};
        auto repeatInterval = findRepeatInterval(jetstream);
        auto simSteps = numRocks % repeatInterval;
        
        for(int64_t i = 0; i < repeatInterval; i++) {
            height = vc.addRock(*itr);
            std::advance(itr, 1);
            if(itr == rockOrder.end()) {
                itr = rockOrder.begin();
            }
        }
//        vc.printChamber();
        
        auto intervalHeight = height;
        finalHeight = intervalHeight * (numRocks / repeatInterval);
//        itr = rockOrder.begin();
        
        for(int64_t i = 0; i < simSteps; i++) {
            height = vc.addRock(*itr);
            std::advance(itr, 1);
            if(itr == rockOrder.end()) {
                itr = rockOrder.begin();
            }
        }
        finalHeight += height-intervalHeight;
        return finalHeight;
    }
}
