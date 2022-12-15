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

		return "---";
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
    
    int32_t countImpossibleSpotsForRow(const std::unordered_map<uint64_t, uint64_t>&sensorToBeacon,int32_t row){
        unordered_set<uint64_t> illegalSpots{};
        unordered_set<uint64_t> takenSpots{};
        int32_t illegalCount{0};
        //Get all locations
        for(const auto& s2b : sensorToBeacon) {
            Coord tmp;
            tmp.all = s2b.first;
//            if(Y(tmp) == row) {
                takenSpots.insert(tmp.all);
//            }
            tmp.all = s2b.second;
//            if(Y(tmp) == row) {
                takenSpots.insert(tmp.all);
//            }
        }
        
        
        for(const auto& s2b : sensorToBeacon) {
            Coord sensor,beacon;
            sensor.all = s2b.first;
            beacon.all = s2b.second;
            int32_t offset{0};
            auto xOffset = abs(X(sensor)-X(beacon));
            auto yOffset = abs(Y(sensor)-Y(beacon));
            offset = xOffset+yOffset;
//            cout << "Beacon at {" << X(beacon) << "," << Y(beacon) << "}..." << endl;
//            cout << "Searching {" << X(sensor) << "," << Y(sensor) << "}...";
            if(row >= Y(sensor)-offset && row <= Y(sensor)+offset) {
                xOffset = offset-abs(row-Y(sensor));
                for(int32_t j = -xOffset; j <= xOffset; j++) {
                    Coord tmp{sensor.all};
                    setX(tmp, X(sensor)+j);
                    setY(tmp, row);
                    if(takenSpots.count(tmp.all) == 0) {
                        //No beacon there so must be impossible
                        //cout << "{" << X(tmp) << "," << Y(tmp) << "}" << endl;
                        if(illegalSpots.count(tmp.all)==0) {
                            illegalSpots.insert(tmp.all);
                            illegalCount++;
//                            cout << "{" << X(tmp) << "," << Y(tmp) << "}" << endl;
                        }
                    }
                }
            }
        }
        return illegalCount;
    }
    
    uint64_t findDistressedBeacon(const std::unordered_map<uint64_t, uint64_t>&sensorToBeacon, const int32_t max) {
        unordered_set<uint64_t> takenSpots{};
        int32_t illegalCountRow{0};
        Coord distressedBeacon{0};
        
        vector<int32_t> invalidCounts{};
        invalidCounts.resize(max,max);
        
        //Get all locations
        for(const auto& s2b : sensorToBeacon) {
            Coord tmp{0};
            tmp.all = s2b.first;
            if(Y(tmp) >= 0 && Y(tmp) <= max) {
                takenSpots.insert(tmp.all);
                invalidCounts[Y(tmp)]--;
            }
            tmp.all = s2b.second;
            if(Y(tmp) >= 0 && Y(tmp) <= max) {
                takenSpots.insert(tmp.all);
                invalidCounts[Y(tmp)]--;
            }
        }

        for(const auto& s2b : sensorToBeacon) {
            Coord sensor,beacon;
            sensor.all = s2b.first;
            beacon.all = s2b.second;
            for(int32_t row = 0; row <= max; row++) {
                int32_t offset{0};
                auto xOffset = abs(X(sensor)-X(beacon));
                auto yOffset = abs(Y(sensor)-Y(beacon));
                offset = xOffset+yOffset;
                //            cout << "Beacon at {" << X(beacon) << "," << Y(beacon) << "}..." << endl;
                //            cout << "Searching {" << X(sensor) << "," << Y(sensor) << "}...";
                if(row >= Y(sensor)-offset && row <= Y(sensor)+offset) {
                    xOffset = offset-abs(row-Y(sensor));
                    for(int32_t j = -xOffset; j <= xOffset; j++) {
                        Coord tmp{sensor.all};
                        setX(tmp, X(sensor)+j);
                        setY(tmp, row);
                        if(X(tmp) >= 0 && X(tmp) <= max) {
                            if(takenSpots.count(tmp.all) == 0) {
                                //No beacon there so must be taken
                                takenSpots.insert(tmp.all);
                                invalidCounts[row]--;
                            }
                        }
                    }
                }
            }
        }
        
        for(int32_t i = 0; i <= max; i++) {
            if(invalidCounts[i] == 1) {
                illegalCountRow = i;
            }
        }
        bool done = false;
        Coord tmp{0};
        setY(tmp,illegalCountRow);
        for(int32_t i = 0; i < max && !done; i++) {
            setX(tmp, i);
            if(takenSpots.count(tmp.all) == 0) {
                distressedBeacon.all = tmp.all;
                done = true;
                cout << "{" << X(tmp) << "," << Y(tmp) << "}" << endl;
            }
        }
        return static_cast<uint64_t>(X(distressedBeacon))*static_cast<uint64_t>(4000000)+static_cast<uint64_t>(Y(distressedBeacon));
    }
}
