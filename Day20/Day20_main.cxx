//
//  Advent of Code 2022 Main Runner: Day 20
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/19/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay20{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day20" << "a: " << AocDay20::solvea() << std::endl;
    std::cout << "Day20" << "b: " << AocDay20::solveb() << std::endl;
    return 0;
}
