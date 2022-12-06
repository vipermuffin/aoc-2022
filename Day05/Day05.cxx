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
		return getfinalOuput(input);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        return getfinalOuput(input, true);
    }
    
    std::vector<std::vector<char>> parseStacksFromInput(const std::vector<std::string>& input) {
        vector<vector<char>> stacks{};
        //Assuming all lines are same length and space delimited
        auto itr = input.begin();
        while(itr != input.end() && !itr->empty()) {
            std::advance(itr, 1);
        }
        
        std::vector<std::string> stackInput{input.begin(),itr};
        auto rItr = stackInput.rbegin();
        std::vector<uint_fast8_t> idxs{};
        //Count how many columns...only works for 0=<col<10
        for(int_fast8_t i = 0; i < rItr->size(); i++) {
            vector<char> tmp{};
            if(rItr->at(i) != ' ') {
                idxs.push_back(i);
                stacks.push_back(tmp);
            }
        }
        std::advance(rItr, 1);
        while(rItr != stackInput.rend()) {
            for(int_fast8_t i = 0; i < idxs.size(); i++) {
                if(idxs[i] < rItr->size() && rItr->at(idxs[i]) != ' ') {
                    stacks[i].push_back(rItr->at(idxs[i]));
                }
            }
            std::advance(rItr, 1);
        }
        return stacks;
    }
    
    std::string getfinalOuput(const std::vector<std::string>& input, bool canMoveFullStack) {
        auto stacks = parseStacksFromInput(input);
        auto itr = input.begin();
        while(!itr->empty()){
            std::advance(itr, 1);
        }
        
        std::advance(itr, 1);
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
            
            //If full stack can be move, need to reverse reverse
            if(canMoveFullStack) {
                std::reverse(temp.begin(), temp.end());
            }
            auto sItr = temp.begin();
            while(sItr != temp.end()) {
                stacks[toCol].push_back(*sItr);
                sItr++;
            }
            std::advance(itr, 1);;
        }
        
        string output("-",stacks.size());
        for(int_fast8_t i = 0; i < stacks.size(); i++) {
            output[i] = stacks[i].back();
        }
        
        return output;
    }

}
