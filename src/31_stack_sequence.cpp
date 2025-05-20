//
// Created by Damon on 2025/5/20.
//

#include "my_algorithms.h"

bool IsStackSeqence(std::vector<int> pushSeq, std::vector<int> popSeq)
{
    std::stack<int> s;
    int popIndex = 0;
    for (int i = 0; i < popSeq.size(); i++) {
        s.push(pushSeq[i]);
        while (!s.empty() && popSeq[popIndex] == s.top()) {
            popIndex++;
            s.pop();
        }
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}
