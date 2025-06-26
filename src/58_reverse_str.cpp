//
// Created by Damon on 2025/6/16.
//

#include "my_algorithms.h"
#include <algorithm>

string RevertStringByWord(string word)
{
    reverse(word.begin(), word.end());
    auto it = word.begin();
    while (it != word.end()) {
        while (it != word.end() && *it == ' ') it++;
        auto left = it;
        while (it != word.end() && *it != ' ') it++;
        reverse(left, it);
    }
    return word;
}

string leftRotateString(string word, int k)
{
    if (k < 0 || word.size() < k) { return word; }
    // 第一种，将前面几个字符全部删除，然后放到当前string的后面
    reverse(word.begin(), word.end());
    // 4, 2,
    int leftSize = word.size() - k;
    auto end = word.begin();
    for (int i = 0; i < leftSize; i++) {
        end++;
    }
    reverse(word.begin(), end);
    reverse(end, word.end());
    return word;
}

