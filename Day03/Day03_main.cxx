//
//  Advent of Code 2022 Main Runner: Day 3
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/02/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day03" << "a: " << AocDay03::solvea() << std::endl;
    std::cout << "Day03" << "b: " << AocDay03::solveb() << std::endl;
    return 0;
}
