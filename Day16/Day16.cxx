//
//  Advent of Code 2022 Solutions: Day 16
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day16.h"
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
#include <unordered_set>


using namespace std;
namespace AocDay16 {

    static const std::string InputFileName = "Day16.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }
    
    void parseLineForValve(const std::string& line,TunnelMap& tm) {
        char inVcStr[5];
        int32_t flowRate;
        sscanf(line.c_str(),"Valve %s has flow rate=%d;", inVcStr, &flowRate);
        std::string inputValve{inVcStr};
        
        //parse csv
        auto pos = line.find("valve");
        auto vOffset = line[pos+6] == ' ' ? pos+7 : pos+6;
        std::string outputValves{line.begin()+vOffset,line.end()};
        vector<string> outputs{};
        auto start = outputValves.begin();
        auto end = outputValves.begin();
        while(start != outputValves.end()) {
            while(end != outputValves.end() && *end != ',') {
                advance(end, 1);
            }
            //comma found
            outputs.emplace_back(start,end);
            if(end != outputValves.end()) {
                advance(end, 1);
            }
            
            //update pointers
            while(end != outputValves.end() && (*end == ',' || *end == ' ')) {
                advance(end, 1);
            }
            start = end;
        }
        tm[inputValve] = make_pair(flowRate, outputs);
    }
    
    TunnelMap buildTunnelMapFromInput(const std::vector<std::string>& input) {
        TunnelMap tm{};
        for(const auto& line : input) {
            parseLineForValve(line,tm);
        }
        return tm;
    }
    
    void buildPath(const TunnelMap& tm, const int32_t numSteps, string currentPath, string currentNode, unordered_map<string, int_fast8_t> visited) {
        if(numSteps == 0) {
            cout << currentPath <<  "," << currentNode << endl;
        } else {
            visited[currentNode]++;
            int32_t nextSteps = visited[currentNode] == 1 ? numSteps-2 : numSteps - 1;
            auto nodeDetails = tm.at(currentNode);
            for(const auto node : nodeDetails.second) {
                if(visited[node] < 3) {
                    buildPath(tm, nextSteps, currentPath+","+currentNode, node, visited);
                }
            }
        }
    }
    
    std::vector<std::string> buildPaths(const TunnelMap& tm,const int32_t numSteps) {
        std::vector<string> paths{};
        paths.reserve(100000);
        string currentNode{"AA"};
        unordered_map<string,int_fast8_t> visitCount{{"AA",1}};
        auto nodeDetails = tm.at(currentNode);
        for(const auto node : nodeDetails.second) {
            buildPath(tm, numSteps-1, currentNode, node, visitCount);
        }
        return paths;
    }
}
