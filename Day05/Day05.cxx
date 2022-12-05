//
//  Advent of Code 2022 Solutions: Day 5
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/04/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay05 {

    static const std::string InputFileName = "Day05.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<vector<char>> stacks {
            {'F','C','J','P','H','T','W'},
            {'G','R','V','F','Z','J','B','H'},
            {'H','P','T','R'},
            {'Z','S','N','P','H','T'},
            {'N','V','F','Z','H','J','C','D'},
            {'P','M','G','F','W','D','Z'},
            {'M','V','Z','W','S','J','D','P'},
            {'N','D','S'},
            {'D','Z','S','F','M'}
        };
        auto itr = input.begin()+10;
        while(itr != input.end()) {
            int32_t num2Move,fromCol,toCol;
            sscanf(itr->c_str(),"move %d from %d to %d", &num2Move, &fromCol, &toCol);
            fromCol--;
            toCol--;
            for(int32_t i = 0; i < num2Move;i++) {
                if(stacks[fromCol].size() > 0) {
                    stacks[toCol].push_back(stacks[fromCol].back());
                    stacks[fromCol].pop_back();
                }
            }
            itr++;
        }
        string output{"---------"};
        for(int32_t i = 0; i < stacks.size(); i++) {
            output[i] = stacks[i].back();
        }
		return output;
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<vector<char>> stacks {
            {'F','C','J','P','H','T','W'},
            {'G','R','V','F','Z','J','B','H'},
            {'H','P','T','R'},
            {'Z','S','N','P','H','T'},
            {'N','V','F','Z','H','J','C','D'},
            {'P','M','G','F','W','D','Z'},
            {'M','V','Z','W','S','J','D','P'},
            {'N','D','S'},
            {'D','Z','S','F','M'}
        };
        auto itr = input.begin()+10;
        while(itr != input.end()) {
            int32_t num2Move,fromCol,toCol;
            sscanf(itr->c_str(),"move %d from %d to %d", &num2Move, &fromCol, &toCol);
            fromCol--;
            toCol--;
            vector<char> temp{};
            temp.reserve(num2Move);
            for(int32_t i = 0; i < num2Move;i++) {
                if(stacks[fromCol].size() > 0) {
                    temp.push_back(stacks[fromCol].back());
                    stacks[fromCol].pop_back();
                }
            }
            auto rItr = temp.rbegin();
            while(rItr != temp.rend()) {
                stacks[toCol].push_back(*rItr);
                rItr++;
            }
            
            itr++;
        }
        string output{"---------"};
        for(int32_t i = 0; i < stacks.size(); i++) {
            output[i] = stacks[i].back();
        }
        return output;
    }

}
