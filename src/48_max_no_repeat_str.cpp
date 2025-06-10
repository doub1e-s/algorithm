//
// Created by Damon on 2025/6/10.
//

#include <my_algorithms.h>
#include <unordered_map>
#include <queue>
#include <algorithm>

int GetMaxNoRepeatStr(const string& str)
{
    unordered_map<char, int> chMap;
    queue<char> chQueue;
    size_t maxSize = 0;
    for (auto& ch : str) {
        if (chMap.find(ch) == chMap.end()) {
            chMap[ch] = 1;
            chQueue.push(ch);
            maxSize = max(maxSize, chQueue.size());
        } else {
            while (chMap[ch] >= 1) {
                char topCh = chQueue.front();
                chMap[topCh]--;
                chQueue.pop();
            }
            chQueue.push(ch);
            chMap[ch]++;
            maxSize = max(maxSize, chQueue.size());
        }
    }
    int res = maxSize;
    return res;
}
