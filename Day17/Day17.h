//
//  Advent of Code 2022 Solutions: Day 17
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/17/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay17 {
//Function Definitions
    class VerticalChamber {
    public:
        VerticalChamber() = delete;
        VerticalChamber(const std::string& windStream);
        ~VerticalChamber() = default;
        int32_t addRock(char rockId);
        void printChamber() const;
        bool repeatDetected() const;
        int32_t getRepeatInterval() const;
        
    private:
        std::string jetPattern;
        std::unordered_map<uint64_t, bool> chamberRockPoints;
        std::unordered_map<char,std::unordered_map<size_t,std::unordered_map<uint64_t,bool>>> initPosition;
        int32_t maxHeight;
        size_t currentJetPatternIdxX2;
        int32_t repeatInterval;
        bool repeated;
    };
    
    int64_t modelRockHeight(std::string& jetstream, const int64_t numRocks);
}
