//
//  Advent of Code 2022 Solutions: Day 8
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/07/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day08.h"
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
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay08 {
constexpr int_fast16_t NumVal(char c) {
    return c - '0';
}
    static const std::string InputFileName = "Day08.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(countVisibleTrees(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findHighestScenicVal(input));
    }
    
int32_t countVisibleTrees(const std::vector<std::string>& grid) {
    int32_t visibleCount{0};
    visibleCount += (grid.size()-2)*2 + 2*grid.back().size();
    for(int_fast16_t y = 1; y < grid.size()-1; y++) {
        for(int_fast16_t x = 1; x < grid[y].size()-1;x++) {
            auto treeSize = NumVal(grid[y][x]);
            auto nvisCnt = 0;
            bool isVis = false;
            //U
            for(int_fast16_t i = 0; i < y && nvisCnt == 0; i++) {
                if(NumVal(grid[i][x]) >= treeSize) {
                    nvisCnt++;
                }
            }
            if(nvisCnt == 0) {
                visibleCount++;
                isVis = true;
            } else {
                nvisCnt = 0;
            }
            //D
            for(int_fast16_t i = y+1; i < grid.size() && nvisCnt == 0; i++) {
                if(NumVal(grid[i][x]) >= treeSize) {
                    nvisCnt++;
                }
            }
            if(!isVis && nvisCnt == 0) {
                visibleCount++;
                isVis = true;
            } else {
                nvisCnt = 0;
            }
            //L
            for(int_fast16_t i = 0; i < x && nvisCnt == 0; i++) {
                if(NumVal(grid[y][i]) >= treeSize) {
                    nvisCnt++;
                }
            }
            if(!isVis && nvisCnt == 0) {
                visibleCount++;
                isVis = true;
            } else {
                nvisCnt = 0;
            }
            //R
            for(int_fast16_t i = x+1; i < grid[y].size() && nvisCnt == 0; i++) {
                if(NumVal(grid[y][i]) >= treeSize) {
                    nvisCnt++;
                }
            }
            if(!isVis && nvisCnt == 0) {
                visibleCount++;
            } 
        }
    }
    return visibleCount;
}
    
    int64_t findHighestScenicVal(const std::vector<std::string>& grid) {
        int64_t maxSceneScore{0};
        
        for(int_fast16_t y = 1; y < grid.size()-1; y++) {
            for(int_fast16_t x = 1; x < grid[y].size()-1;x++) {
                int64_t currentScore{1};
                auto treeSize = NumVal(grid[y][x]);
                auto visCnt = 0;
                bool blocked = false;
                //U
                for(int_fast16_t i = y-1; i >= 0 && !blocked; i--) {
                    visCnt++;
                    if(NumVal(grid[i][x]) >= treeSize) {
                        blocked = true;
                    }
                }
                currentScore *= visCnt;
                blocked = false;
                visCnt = 0;
                //D
                for(int_fast16_t i = y+1; i < grid.size() && !blocked; i++) {
                    visCnt++;
                    if(NumVal(grid[i][x]) >= treeSize) {
                        blocked = true;
                    }
                }
                currentScore *= visCnt;
                blocked = false;
                visCnt = 0;
                //L
                for(int_fast16_t i = x-1; i >= 0 && !blocked; i--) {
                    visCnt++;
                    if(NumVal(grid[y][i]) >= treeSize) {
                        blocked = true;
                    }
                }
                currentScore *= visCnt;
                blocked = false;
                visCnt = 0;
                //R
                for(int_fast16_t i = x+1; i < grid[y].size() && !blocked; i++) {
                    visCnt++;
                    if(NumVal(grid[y][i]) >= treeSize) {
                        blocked = true;
                    }
                }
                currentScore *= visCnt;
                blocked = false;
                
                if(currentScore > maxSceneScore) {
                    maxSceneScore = currentScore;
                }
            }
        }
        return maxSceneScore;
    }

}
