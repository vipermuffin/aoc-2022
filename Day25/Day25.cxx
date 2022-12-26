//
//  Advent of Code 2022 Solutions: Day 25
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/25/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <sstream>


using namespace std;
namespace AocDay25 {

    static const std::string InputFileName = "Day25.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
		return encodeSnafuNumber(sumSnafuList(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

int64_t decodeSnafuNumber(const std::string& snafuNum) {
    int64_t result{0};
    bool dec = false;
    auto itr = snafuNum.rbegin();
    int64_t inc = 1;
    while(itr != snafuNum.rend()) {
        int64_t val = 0;
        switch(*itr) {
            case '1':
            case '2':
            case '0':
                val = static_cast<int64_t>(*itr - '0' - (dec ? 1 : 0));
                dec = false;
                break;
            case '=':
                val = dec ? 2 : 3;
                dec = true;
                break;
            case '-':
                val = dec ? 3 : 4;
                dec = true;
                break;
            default:
                dec = false;
                break;
        }
        result += val * inc;
        inc *=5;
        std::advance(itr, 1);
    }
    return result;
}

std::string base10to5(int64_t num) {
    stringstream ss{};
    while(num > 0) {
        ss << to_string(num%5);
        num /= 5;
    }
    string result{ss.str()};
    std::reverse(result.begin(), result.end());
    return result;
}

std::string encodeSnafuNumber(const int64_t num) {
    auto b5num = base10to5(num);
    stringstream ss{};
    bool inc = false;
    auto itr = b5num.rbegin();
    const vector<std::pair<char,bool>> lookup {
        {'0',false},{'1',false},{'2',false},
        {'=',true},{'-',true},{'0',true}
    };
    while(itr != b5num.rend()) {
        size_t index = static_cast<size_t>(*itr - '0' + (inc ? 1 : 0));
        ss << lookup[index].first;
        inc = lookup[index].second;
        std::advance(itr,1);
    }
    if(inc) {
        ss << '1';
    }
    b5num = ss.str();
    std::reverse(b5num.begin(), b5num.end());
    return b5num;
}

int64_t sumSnafuList(const std::vector<std::string>& listOfNumbers) {
    vector<int64_t> vals{};
    for(const auto& line : listOfNumbers) {
        vals.push_back(decodeSnafuNumber(line));
    }
    return std::accumulate(vals.begin(), vals.end(), static_cast<int64_t>(0));
}
}
