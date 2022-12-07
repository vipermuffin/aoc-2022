//
//  Advent of Code 2022 Solutions: Day 7
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/06/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <map>
#include <vector>

namespace AocDay07 {
//Function Definitions
int64_t findSumOfDirsLessThanSize(const std::vector<std::string>&, const int64_t);
int64_t findSizeOfDirToDelete(const std::vector<std::string>&, const int64_t, const int64_t);
int64_t updateFilesystem(std::map<std::string,int64_t>& dirs, std::map<std::string,int64_t>& files, const std::string path, std::vector<std::string>::const_iterator& itr, std::vector<std::string>::const_iterator& end);
}
