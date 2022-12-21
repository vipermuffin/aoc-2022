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
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay20 {

    struct Node {
        Node() : val{ 0 }, loopVal{ 0 }, prev{ nullptr }, next{ nullptr }{}
        ~Node() = default;
        int64_t val;
        int64_t loopVal;
        Node* prev;
        Node* next;
    };
    static const std::string InputFileName = "Day20.txt";
    std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        return to_string(performMixing(input));
    }

    std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        return to_string(performMixing(input, 811589153, 10));
    }

    int64_t performMixing(const vector<int>& input, int64_t key, int32_t runs) {
        vector<Node> nodeList{};
        nodeList.reserve(input.size());
        Node* zeroPtr = nullptr;
        for (const auto& x : input) {
            Node tmp{};
            tmp.val = x * key;
            tmp.loopVal = tmp.val;
            bool isZero = false;
            if (tmp.loopVal > 0) {
                tmp.loopVal -= (input.size() - 1) * (tmp.val / (input.size() - 1));
            }
            else if (tmp.loopVal < 0) {
                tmp.loopVal += (input.size() - 1) * (tmp.val / (-static_cast<int64_t>(input.size() - 1)));
            }
            else {
                isZero = true;
            }
            //cout << tmp.val << ",";
            nodeList.push_back(tmp);
            if (isZero) {
                zeroPtr = &nodeList.back();
            }
        }
        //cout << endl;
        nodeList[0].prev = &nodeList.back();
        nodeList[0].next = &nodeList[1];
        nodeList.back().prev = &nodeList[nodeList.size() - 2];
        nodeList.back().next = &nodeList[0];
        for (int i = 1; i < nodeList.size() - 1; i++) {
            nodeList[i].prev = &nodeList[i - 1];
            nodeList[i].next = &nodeList[i + 1];
        }

        auto itr = nodeList.begin();
        for (int run = 0; run < runs; run++) {
            itr = nodeList.begin();
            auto numElements = nodeList.size();
            while (itr != nodeList.end()) {
                auto x = itr->loopVal;
                if (x != 0) {
                    Node* nodePtr = itr->next->prev;
                    Node* ptr = nodePtr;
                    //remove from list
                    itr->prev->next = itr->next;
                    itr->next->prev = itr->prev;
                    if (x > 0) {
                        for (int i = 0; i < x; i++) {
                            ptr = ptr->next;
                        }
                    }
                    else {
                        for (int i = x; i <= 0; i++) {
                            ptr = ptr->prev;
                        }
                    }
                    //insert back into the list
                    nodePtr->next = ptr->next;
                    ptr->next->prev = nodePtr;
                    nodePtr->prev = ptr;
                    ptr->next = nodePtr;

                }
                itr++;
            }
        }
        Node* ptr = zeroPtr;

        Node* nodes[3] = { nullptr };
        for (int i = 0; i < 3000; i++) {
            ptr = ptr->next;
            nodes[i / 1000] = ptr;
        }

        return nodes[0]->val + nodes[1]->val + nodes[2]->val;
    }

}
