//
//  Advent of Code 2022 Tests: Day 7
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/06/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay07{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(Y2022_SolveDay7, FinalSolutionPartA) {
    EXPECT_EQ("1325919", solvea());
}

TEST(Y2022_SolveDay7, FinalSolutionPartB) {
    EXPECT_EQ("2050735", solveb());
}

TEST(Y2022_Day7Example,Test1) {
    vector<string> input {
        "$ cd /",
        "$ ls",
        "dir a",
        "14848514 b.txt",
        "8504156 c.dat",
        "dir d",
        "$ cd a",
        "$ ls",
        "dir e",
        "29116 f",
        "2557 g",
        "62596 h.lst",
        "$ cd e",
        "$ ls",
        "584 i",
        "$ cd ..",
        "$ cd ..",
        "$ cd d",
        "$ ls",
        "4060174 j",
        "8033020 d.log",
        "5626152 d.ext",
        "7214296 k"
    };
    map<string,int64_t> directories{};
    map<string,int64_t> files{};
    std::vector<std::string>::const_iterator itr = input.begin();
    std::vector<std::string>::const_iterator end = input.end();
    string startPath{};
    auto val = updateFilesystem(directories, files, startPath, itr, end);
    EXPECT_EQ(48381165,val);
}

TEST(Y2022_Day7Example,Test2) {
    vector<string> input {
        "$ cd /",
        "$ ls",
        "dir a",
        "14848514 b.txt",
        "8504156 c.dat",
        "dir d",
        "$ cd a",
        "$ ls",
        "dir e",
        "29116 f",
        "2557 g",
        "62596 h.lst",
        "$ cd e",
        "$ ls",
        "584 i",
        "$ cd ..",
        "$ cd ..",
        "$ cd d",
        "$ ls",
        "4060174 j",
        "8033020 d.log",
        "5626152 d.ext",
        "7214296 k"
    };
    EXPECT_EQ(95437,findSumOfDirsLessThanSize(input, 100000));
}

TEST(Y2022_Day7Example,Test3) {
    vector<string> input {
        "$ cd /",
        "$ ls",
        "dir a",
        "14848514 b.txt",
        "8504156 c.dat",
        "dir d",
        "$ cd a",
        "$ ls",
        "dir e",
        "29116 f",
        "2557 g",
        "62596 h.lst",
        "$ cd e",
        "$ ls",
        "584 i",
        "$ cd ..",
        "$ cd ..",
        "$ cd d",
        "$ ls",
        "4060174 j",
        "8033020 d.log",
        "5626152 d.ext",
        "7214296 k"
    };
    EXPECT_EQ(24933642,findSizeOfDirToDelete(input, 70000000, 30000000));
}
