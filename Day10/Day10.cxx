//
//  Advent of Code 2022 Solutions: Day 10
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/09/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <numeric> //std::accumulate
#include <unordered_map>


using namespace std;
namespace AocDay10 {

    static const std::string InputFileName = "Day10.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto result = runProgram(input, 1);
        return to_string(std::accumulate(result.begin(), result.end(), static_cast<int64_t>(0)));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto result = runProgram2(input, 1);
        for(const auto& line : result) {
            cout << line << endl;
        }
		return "---";
    }
    
    std::vector<int64_t> runProgram(const std::vector<std::string>& ins, int64_t startVal) {
        vector<int64_t> output{};
        output.reserve(20);
        int64_t cycleCount = 1;
        int64_t nextKeyCycle = 20;
        int64_t xReg{startVal};
        function<void()> checkForKeyCycle = [&]() {
            if(cycleCount == nextKeyCycle) {
                output.push_back(cycleCount*xReg);
                nextKeyCycle += 40;
            }
        };
        unordered_map<std::string, std::function<void(int32_t)>> cpu {
            {"noop",[&](int32_t){checkForKeyCycle();cycleCount++;}},
            {"addx",[&](int32_t val){checkForKeyCycle();cycleCount++; checkForKeyCycle();xReg += val;cycleCount++;}}
        };

        
        for(const auto& opCode : ins) {
            auto words = parseLineForWords(opCode);
            cpu[words[0]](words.size() > 1 ? stoi(words[1]) : 0);
        }

        return output;
    }
    
    std::vector<std::string> runProgram2(const std::vector<std::string>& ins, int64_t startVal) {
        constexpr int WIDTH = 40;
        constexpr int HEIGHT = 6;
        string output(WIDTH*HEIGHT,'-');
        int64_t cycleCount = 1;
        int64_t xReg{startVal};
        function<void()> checkForKeyCycle = [&]() {
            int targetPixel = cycleCount-1;
            int targetRowPixel = targetPixel%WIDTH;
            if(targetRowPixel == xReg-1 ||
               targetRowPixel == xReg   ||
               targetRowPixel == xReg+1) {
                output[targetPixel] = '#';
            } else {
                output[targetPixel] = '.';
            }
        };
        unordered_map<std::string, std::function<void(int32_t)>> cpu {
            {"noop",[&](int32_t){checkForKeyCycle();cycleCount++;}},
            {"addx",[&](int32_t val){checkForKeyCycle();cycleCount++; checkForKeyCycle();xReg += val;cycleCount++;}}
        };

        for(const auto& opCode : ins) {
            auto words = parseLineForWords(opCode);
            cpu[words[0]](words.size() > 1 ? stoi(words[1]) : 0);
        }
        vector<string> vOutput{};
        vOutput.reserve(HEIGHT);
        auto sbItr = output.begin();
        auto seItr = output.begin()+WIDTH;
        while(seItr <= output.end()) {
            vOutput.emplace_back(sbItr,seItr);
            std::advance(sbItr, WIDTH);
            std::advance(seItr, WIDTH);
        }
        return vOutput;
    }
}
