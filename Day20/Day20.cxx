//
//  Advent of Code 2022 Solutions: Day 20
//
//  https://adventofcode.com/2022
//
//  Created by vipermuffin on 12/19/2022.
//  Copyright © 2022 vipermuffin. All rights reserved.
//

#include "Day20.h"
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
//#include <unordered_set>


using namespace std;
namespace AocDay20 {

struct Node {
    Node(): val{0},prev{nullptr},next{nullptr}{}
    ~Node() = default;
    int32_t val;
    Node* prev;
    Node* next;
};
    static const std::string InputFileName = "Day20.txt";
    std::string solvea() {
        //757 too low
        //15277 too high
        auto input = parseFileForNumberPerLine(InputFileName);
        
		return to_string(performMixing(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

int64_t performMixing(const vector<int>& input) {
    vector<Node> nodeList{};
    nodeList.reserve(input.size());
    for(const auto& x : input) {
        Node tmp{};
        tmp.val = x;
        nodeList.push_back(tmp);
    }
    nodeList[0].prev = &nodeList.back();
    nodeList[0].next = &nodeList[1];
    nodeList[nodeList.size()-1].prev = &nodeList[nodeList.size()-2];
    nodeList[nodeList.size()-1].next = &nodeList[0];
    for(int i = 1; i < nodeList.size()-1;i++) {
        nodeList[i].prev = &nodeList[i-1];
        nodeList[i].next = &nodeList[i+1];
    }
    
    auto itr = nodeList.begin();
    auto numElements = nodeList.size();
    while(itr != nodeList.end()) {
        auto x = itr->val;
        if(x != 0) {
            Node* nodePtr = itr->next->prev;
            Node* ptr = nodePtr;
            //remove from list
            itr->prev->next = itr->next;
            itr->next->prev = itr->prev;
            if( x > 0) {
//                x %= nodeList.size();
                for(int i = 0; i < x; i++) {
                    ptr = ptr->next;
                }
            } else {
//                x = -x % nodeList.size();
//                x = -x;
                for(int i = x; i <= 0; i++) {
                    ptr = ptr->prev;
                }
            }
//            //remove from list
//            itr->prev->next = itr->next;
//            itr->next->prev = itr->prev;
            nodePtr->next = ptr->next;
            ptr->next->prev = nodePtr;
            nodePtr->prev = ptr;
            ptr->next = nodePtr;
            
//            cout << "{";
//            for(int i = 0; i < nodeList.size();i++) {
//                cout << "," << ptr->val;
//                ptr = ptr->next;
//            }
//            cout << endl;
        }
        itr++;
    }
    itr = nodeList.begin();
    while(itr != nodeList.end() && itr->val != 0) {
        itr++;
    }
    Node* ptr = &nodeList[std::distance(nodeList.begin(), itr)];
//    for(int i = 0; i < nodeList.size();i++) {
//        cout << "," << ptr->val;
//        ptr = ptr->next;
//    }
    
    Node* nodes[3];
    nodes[0] = ptr;
    nodes[1] = ptr;
    nodes[2] = ptr;
    for(int i = 0; i < 1000; i++) {
        ptr = ptr->next;
    }
    nodes[0] = ptr;
    for(int i = 0; i < 1000; i++) {
        ptr = ptr->next;
    }
    nodes[1] = ptr;
    for(int i = 0; i < 1000; i++) {
        ptr = ptr->next;
    }
    nodes[2] = ptr;
//    cout << nodes[0]->val <<","<<nodes[1]->val<<"," <<nodes[2]->val << endl;
    return nodes[0]->val+nodes[1]->val+nodes[2]->val;
}

}
