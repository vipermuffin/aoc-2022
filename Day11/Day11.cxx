//
//  Advent of Code 2022 Solutions: Day 11
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/10/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function


using namespace std;
namespace AocDay11 {
template<typename T>
T gcf(T a, T b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if(a == b) {
        return a;
    }
    auto newA = a > b ? a : b;
    auto newB = a > b ? b : a;
    
    auto c = newA;
    while(c > newB) {
        c -= newB;
    }
    
    return gcf<T>(c,newB);
}

template<typename T>
T lcm(T a, T b) {
    auto gcd = gcf<T>(a,b);
    return gcd>0 ? (a*b)/gcd : 0;
}

int64_t calculateReducer(std::vector<Monkey>& monkeys) {
    auto itr = monkeys.begin();
    int64_t currentLcm{1};
    while(itr != monkeys.end()) {
        int64_t nextLcm = lcm<int64_t>(currentLcm,itr->worryTestDivVal);
        currentLcm = nextLcm;
        std::advance(itr, 1);
    }
    return currentLcm;
}

    static const std::string InputFileName = "Day11.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto monkeys = initMonkeys(input);
        auto result = processMonkeyBusiness(monkeys, 20);
		return to_string(result);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto monkeys = initMonkeys(input);
        auto result = processMonkeyBusiness(monkeys, 10000, true);
        return to_string(result);
    }
vector<Monkey> initMonkeys(const std::vector<std::string>&input) {
    vector<Monkey> monkeys{};
    Monkey m{};
    auto itr = input.begin();
    auto eItr = input.begin();
    while(eItr != input.end() && !eItr->empty()) {
        std::advance(eItr, 1);
    }
    while(itr != input.end()) {
        vector<string> mStrs{itr,eItr};
        m.items.clear();
        //move to items line
        std::advance(itr, 1);
        string itemString{itr->begin()+16,itr->end()};
        auto items = parseCsvLineForLongNum(itemString);
        for_each(items.begin(),items.end(),[&](int64_t x){m.items.push_back(x);});
        //Parse Operation
        std::advance(itr, 1);
        auto ops = parseLineForWords(*itr);
        if(ops[5] == "old") {
            m.worryOperation = 2;
            m.worryAdjustment = 0;
        } else {
            m.worryOperation = ops[4][0]-'*';
            m.worryAdjustment = std::stol(ops[5]);
        }
        //Parse div test
        std::advance(itr, 1);
        m.worryTestDivVal = std::stol(parseLineForWords(*itr)[3]);
        std::advance(itr, 1);
        m.trueMonkey = static_cast<size_t>(std::stoi(parseLineForWords(*itr)[5]));
        std::advance(itr, 1);
        m.falseMonkey = static_cast<size_t>(std::stoi(parseLineForWords(*itr)[5]));
        std::advance(itr, 2);
        if(eItr != input.end()) {
            std::advance(eItr, 7);
        } else {
            itr = input.end();
        }
        
        monkeys.push_back(m);
    }
    
    return monkeys;
}

int64_t processMonkeyBusiness(std::vector<Monkey>& monkeys,int32_t numRounds, bool extraWorried) {
    const vector<std::function<void(int64_t&,const int64_t)>> adjustWorry{
        {[](int64_t& w,const int64_t adj){w *= adj;}},
        {[](int64_t& w,const int64_t adj){w += adj;}},
        {[](int64_t& w,const int64_t){w *= w;}}
    };
    auto reducer = calculateReducer(monkeys);
    for(int i = 0; i < numRounds; i++) {
        for(auto& monkey : monkeys) {
            for(auto item : monkey.items) {
                monkey.itemsInspected++;
                adjustWorry[monkey.worryOperation](item,monkey.worryAdjustment);
                item = extraWorried ? item % reducer : item / 3;
                size_t newMonkey = (item%monkey.worryTestDivVal==0) ? monkey.trueMonkey : monkey.falseMonkey;
                monkeys[newMonkey].items.push_back(item);
            }
            monkey.items.clear();
        }
        
    }
    vector<int64_t> finalItemsInspected{};
    for(const auto& monkey : monkeys) {
        finalItemsInspected.push_back(monkey.itemsInspected);
    }

    std::sort(finalItemsInspected.begin(),finalItemsInspected.end());
    auto rItr = finalItemsInspected.rbegin();
    return *rItr**std::next(rItr);
}

}
