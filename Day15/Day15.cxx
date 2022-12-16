//
//  Advent of Code 2022 Solutions: Day 15
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/15/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day15.h"
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
namespace AocDay15 {

    void setX(Coord& position,int32_t xVal) {
        position.xy[xIdx] = xVal;
    }

    void setY(Coord& position,int32_t yVal) {
        position.xy[yIdx] = yVal;
    }
    
    static const std::string InputFileName = "Day15.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto s2b = getBeaconMap(input);

		return to_string(countImpossibleSpotsForRow(s2b, 2000000));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto s2b = getBeaconMap(input);

		return to_string(findDistressedBeacon(s2b, 4000000));
    }

    std::unordered_map<uint64_t, uint64_t> getBeaconMap(const std::vector<std::string>& beaconInput) {
        std::unordered_map<uint64_t, uint64_t> sensorToBeacon;
        for(const auto& line : beaconInput) {
            int32_t sx,sy,bx,by;
            Coord tmpS,tmpB;
            sscanf(line.c_str(), "Sensor at x=%i, y=%i: closest beacon is at x=%i, y=%i",&sx,&sy,&bx,&by);
            setX(tmpS, sx);
            setY(tmpS, sy);
            setX(tmpB, bx);
            setY(tmpB, by);
            sensorToBeacon[tmpS.all] = tmpB.all;
        }
        return sensorToBeacon;
    }
    
    int32_t countImpossibleSpotsForRow(const std::unordered_map<uint64_t, uint64_t>&sensorToBeacon,int32_t row, Coord* distressed, int32_t rMax){
        unordered_set<uint64_t> illegalSpots{};
        unordered_set<uint64_t> takenSpots{};
        
        vector<std::pair<int32_t,int32_t>> ranges{};
        ranges.reserve(sensorToBeacon.size());
        for(const auto& s2b : sensorToBeacon) {
            Coord sensor,beacon;
            sensor.all = s2b.first;
            beacon.all = s2b.second;
            int32_t offset{0};
            auto xOffset = abs(X(sensor)-X(beacon));
            auto yOffset = abs(Y(sensor)-Y(beacon));
            offset = xOffset+yOffset;
            if(row >= Y(sensor)-offset && row <= Y(sensor)+offset) {
                xOffset = offset-abs(row-Y(sensor));
                int32_t xMin =X(sensor)-xOffset;
                int32_t xMax = X(sensor)+xOffset;
                if(distressed != nullptr) {
                    if(xMin < 0) {
                        xMin = 0;
                    }
                    if(xMax > rMax) {
                        xMax = rMax;
                    }
                }
                ranges.emplace_back(xMin,xMax);
            }
        }
        
        
        bool done = false;
        while(!done) {
            vector<std::pair<int32_t, int32_t>> newRanges{};
            newRanges.reserve(ranges.size());
            done = true;
            auto itr = ranges.begin();
            auto currentRange = *itr++;
            while(itr != ranges.end()) {
                //Check for overlap
                if( (itr->first <= currentRange.first && currentRange.first <= itr->second) ||
                    (itr->second<= currentRange.second && currentRange.second <= itr->first)||
                    (currentRange.first <= itr->first && itr->first <= currentRange.second) ||
                    (currentRange.second <= itr->second && itr->second <= currentRange.first)) {
                    done = false;
                    //Overlap detected
//                    cout << "Overlap: {" << currentRange.first << "," << currentRange.second << "} {" << itr->first << "," << itr->second << "} --> {";
                    currentRange.first = min(currentRange.first,itr->first);
                    currentRange.second = max(currentRange.second,itr->second);
//                    cout << currentRange.first << "," << currentRange.second << "}" << endl;
                } else {
//                    cout << "NO Overlap: {" << currentRange.first << "," << currentRange.second << "} {" << itr->first << "," << itr->second << "}" << endl;
                    newRanges.push_back(*itr);
                }
                std::advance(itr, 1);
            }
            if(newRanges.empty()) {
                newRanges.push_back(currentRange);
            } else if(newRanges.back().first != currentRange.first && newRanges.back().second != currentRange.second) {
                newRanges.push_back(currentRange);
            }
            
            std::swap(ranges,newRanges);
        }
        int32_t illegalCount{0};
        for(const auto& p : ranges) {
            illegalCount += p.second - p.first;
        }
        if(distressed != nullptr && illegalCount == (rMax-2)) {
            setY(*distressed,row);
            //assuming not at 0
            if(ranges.front().first == 0) {
                setX(*distressed,ranges.front().second+1);
            } else {
                setX(*distressed,ranges.back().second+1);
            }
        }
        return illegalCount;
    }
    
    uint64_t findDistressedBeacon(const std::unordered_map<uint64_t, uint64_t>&sensorToBeacon, const int32_t max) {
        Coord distressedBeacon{0};
        for(int32_t i = 0; i < max; i++) {
            auto val = countImpossibleSpotsForRow(sensorToBeacon, i, &distressedBeacon, max);
//            cout << val << endl;
        }
        return static_cast<uint64_t>(X(distressedBeacon))*static_cast<uint64_t>(4000000)+static_cast<uint64_t>(Y(distressedBeacon));
    }
}
