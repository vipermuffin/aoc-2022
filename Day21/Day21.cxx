//
//  Advent of Code 2022 Solutions: Day 21
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/21/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
#include <functional> //std::function
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
namespace AocDay21 {

    static const std::string InputFileName = "Day21.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(processMonkeyBusiness(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        //1229786659545576402 too high
        //1475743247195037089 too high
        //3721298272960 too high

		return to_string(processMonkeyBusiness2(input));
    }
    
    int64_t processMonkeyBusiness(const std::vector<std::string>& input) {
        unordered_map<string, int64_t> monkeys{};
        vector<vector<string>> stack{};
        
        //Init stack
        for(auto line : input) {
            line[4] = ' ';
            auto splitStr = parseLineForWords(line);
            if(splitStr.size() == 2) {
                monkeys[splitStr.front()] = stol(splitStr.back());
            } else {
                stack.push_back(splitStr);
            }
        }
        unordered_map<string,function<int64_t(int64_t,int64_t)>> ops {
            {"+",[](int64_t x,int64_t y){return x+y;}},
            {"-",[](int64_t x,int64_t y){return x-y;}},
            {"*",[](int64_t x,int64_t y){return x*y;}},
            {"/",[](int64_t x,int64_t y){return x/y;}},
        };
        while(!stack.empty()) {
            vector<vector<string>> newStack{};
            for(const auto& formula : stack) {
                if(monkeys.count(formula[1]) > 0 && monkeys.count(formula[3]) > 0) {
                    monkeys[formula[0]] = ops[formula[2]](monkeys[formula[1]],monkeys[formula[3]]);
                } else {
                    newStack.push_back(formula);
                }
            }
            std::swap(stack,newStack);
        }
        return monkeys["root"];
    }
    
    int64_t processMonkeyBusiness2(const std::vector<std::string>& input) {
        unordered_map<string, int64_t> initMonkeys{};
        vector<vector<string>> initStack{};
        
        //Init stack
        for(auto line : input) {
            line[4] = ' ';
            auto splitStr = parseLineForWords(line);
            if(splitStr.size() == 2) {
                initMonkeys[splitStr.front()] = stol(splitStr.back());
            } else {
                if(splitStr[0] == "root") {
                    splitStr[2] = "=";
                }
                initStack.push_back(splitStr);
            }
        }
        initMonkeys["humn"] = 0;
        unordered_map<string,function<int64_t(int64_t,int64_t)>> ops {
            {"+",[](int64_t x,int64_t y){return x+y;}},
            {"-",[](int64_t x,int64_t y){return x-y;}},
            {"*",[](int64_t x,int64_t y){return x*y;}},
            {"/",[](int64_t x,int64_t y){return x/y;}},
            {"=",[](int64_t x,int64_t y){if(x==y){return 0;} else if (x > y){return 1;} else {return -1;}}}
        };
        bool done = false;
        vector<vector<string>> stack{};
        unordered_map<string, int64_t> monkeys{};
        int64_t min{0}, max{INT64_MAX}, index{0}, inc{INT64_MAX>>8}, minIndex{INT64_MAX};
        bool firstRun = true;
        int64_t lowDir = 0;
        int64_t lastDir = 0;
        while(!done) {
            stack = initStack;
            monkeys = initMonkeys;
            monkeys["humn"] = index;
            while(!stack.empty()) {
                vector<vector<string>> newStack{};
                for(const auto& formula : stack) {
                    if(monkeys.count(formula[1]) > 0 && monkeys.count(formula[3]) > 0) {
//                        if(formula[0] == "root") {
//                            cout << monkeys[formula[1]] << "," << monkeys[formula[3]] << "," << monkeys["humn"] << " --> {" << min << "," << max << "}" << endl;
//                        }
                        monkeys[formula[0]] = ops[formula[2]](monkeys[formula[1]],monkeys[formula[3]]);
                    } else {
                        newStack.push_back(formula);
                    }
                }
                std::swap(stack,newStack);
            }
            
            if(firstRun) {
                //determine direction to binary search assuming 0 is too low
                firstRun = false;
                lowDir = monkeys["root"];
                lastDir = lowDir;
            } else if(monkeys["root"] == 0) {
                if(index < minIndex) {
                    minIndex = index;
                }
                index--;
            } else if(monkeys["root"] == lowDir){
                //too low
                //min = index+1;
                index+=inc;
            } else {
                //too high
                //max = index-1;
                index-=inc;
            }
            if(inc == 0) {
                done = true;
            }
            if(lastDir != monkeys["root"]) {
                inc >>= 1;
                lastDir = monkeys["root"];
            }
            //index = (max - min)/2+min;
            
        }
        
        return minIndex;//monkeys["humn"];
    }
    
//    int64_t processMonkeyBusiness2(const std::vector<std::string>& input) {
//        unordered_map<string, int64_t> initMonkeys{};
//        vector<vector<string>> initStack{};
//
//        //Init stack
//        for(auto line : input) {
//            line[4] = ' ';
//            auto splitStr = parseLineForWords(line);
//            if(splitStr.size() == 2) {
//                initMonkeys[splitStr.front()] = stol(splitStr.back());
//            } else {
//                if(splitStr[0] == "root") {
//                    splitStr[2] = "=";
//                }
//                initStack.push_back(splitStr);
//            }
//        }
//        initMonkeys["humn"] = 0;
//        unordered_map<string,function<int64_t(int64_t,int64_t)>> ops {
//            {"+",[](int64_t x,int64_t y){return x+y;}},
//            {"-",[](int64_t x,int64_t y){return x-y;}},
//            {"*",[](int64_t x,int64_t y){return x*y;}},
//            {"/",[](int64_t x,int64_t y){return x/y;}},
//            {"=",[](int64_t x,int64_t y){if(x==y){return 0;} else if (x > y){return 1;} else {return -1;}}}
//        };
//        bool done = false;
//        vector<vector<string>> stack{};
//        unordered_map<string, int64_t> monkeys{};
//        int64_t min{0}, max{INT64_MAX}, index{0}, minIndex{INT64_MAX};
//        bool firstRun = true;
//        int64_t lowDir = 0;
//
//        while(!done) {
//            stack = initStack;
//            monkeys = initMonkeys;
//            monkeys["humn"] = index;
//            while(!stack.empty()) {
//                vector<vector<string>> newStack{};
//                for(const auto& formula : stack) {
//                    if(monkeys.count(formula[1]) > 0 && monkeys.count(formula[3]) > 0) {
//                        if(formula[0] == "root") {
//                            cout << monkeys[formula[1]] << "," << monkeys[formula[3]] << "," << monkeys["humn"] << " --> {" << min << "," << max << "}" << endl;
//                        }
//                        monkeys[formula[0]] = ops[formula[2]](monkeys[formula[1]],monkeys[formula[3]]);
//                    } else {
//                        newStack.push_back(formula);
//                    }
//                }
//                std::swap(stack,newStack);
//            }
//            if(firstRun) {
//                //determine direction to binary search assuming 0 is too low
//                firstRun = false;
//                lowDir = monkeys["root"];
//            } else if(monkeys["root"] == 0) {
//                done = true;
//            } else if(monkeys["root"] == lowDir){
//                //too low
//                min = index+1;
//            } else {
//                //too high
//                max = index-1;
//            }
//            if(min > max) {
//                //Seems we didn't find it.  Flip direction
//                lowDir = -lowDir;
//                min = 0;
//                max = INT64_MAX;
//                index = INT32_MAX;
//            }
//            index = (max - min)/2+min;
//
//        }
//
//        return monkeys["humn"];
//    }
}
