//
//  Advent of Code 2022 Solutions: Day 7
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/06/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay07 {

    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findSumOfDirsLessThanSize(input, 100000));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findSizeOfDirToDelete(input, 70000000, 30000000));
    }

    int64_t findSumOfDirsLessThanSize(const std::vector<std::string>& input, const int64_t maxSize) {
        map<string,int64_t> directories{};
        map<string,int64_t> files{};
        auto itr = input.begin();
        auto end = input.end();
        string startPath{};
        updateFilesystem(directories, files, startPath, itr, end);
        int64_t sumOfDirsLessThanMaxSize{0};
        for(const auto& kvp : directories) {
            if(kvp.second <= maxSize) {
                sumOfDirsLessThanMaxSize += kvp.second;
            }
        }
        return sumOfDirsLessThanMaxSize;
    }

    int64_t updateFilesystem(std::map<std::string,int64_t>& dirs, std::map<std::string,int64_t>& files, const std::string path, std::vector<std::string>::const_iterator& itr, std::vector<std::string>::const_iterator& end) {
        int64_t sumSize{0};
        
        while(itr != end) {
            auto words = parseLineForWords(*itr);
            std::advance(itr, 1);
            if(words[0] == "$") {
                if(words[1] == "cd") {
                    if(words[2] == "..") {
                        return sumSize;
                    } else if(words[2] == "/") {
                        //initialize path
                        string newPath{words[2]};
                        int64_t folderSize = updateFilesystem(dirs, files, newPath, itr, end);
                        dirs[newPath] = folderSize;
                        sumSize += folderSize;
                    }else {
                        string newPath{path};
                        if(newPath != "/") {
                            newPath.append("/");
                        }
                        newPath.append(words[2]);
                        int64_t folderSize = updateFilesystem(dirs, files, newPath, itr, end);
                        dirs[newPath] = folderSize;
                        sumSize += folderSize;
                    }
                } else if(words[1] == "ls") {
                    string newPath{path + "/"};
                    bool done = false;
                    while(itr != end && !done) {
                        auto lsOutput = parseLineForWords(*itr);
                        if(lsOutput[0] == "dir") {
                            //Do nothing except look at next line
                            std::advance(itr, 1);
                        } else if(lsOutput[0] == "$") {
                            //Next command found...do nothing and signal done
                            done = true;
                        } else {
                            //assuming file -> size filename
                            string fileName{path};
                            if(path != "/") {
                                fileName.append("/");
                            }
                            fileName.append(lsOutput[1]);
                            if(files.count(fileName) == 0) {
                                //Don't double count if list dir twice although..probably not correct if did
                                int64_t filesize = stol(lsOutput[0]);
                                files[fileName] = filesize;
                                sumSize += filesize;
                            }
                            std::advance(itr, 1);
                        }
                        
                    }
                }
            }
        }
        return sumSize;
    }

    int64_t findSizeOfDirToDelete(const std::vector<std::string>& input, const int64_t capacity, const int64_t updateSpaceRequired) {
        map<string,int64_t> directories{};
        map<string,int64_t> files{};
        auto itr = input.begin();
        auto end = input.end();
        string startPath{};
        updateFilesystem(directories, files, startPath, itr, end);
        
        auto totalUsed = directories["/"];
        int64_t neededSpace = updateSpaceRequired - (capacity - totalUsed);
        int64_t bestDirSize{LONG_MAX};
        for(const auto& kvp : directories) {
            if(kvp.second >= neededSpace && kvp.second < bestDirSize) {
                bestDirSize = kvp.second;
            }
        }
        return bestDirSize;
    }
}
