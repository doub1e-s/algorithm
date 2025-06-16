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
        while (*it == ' ') {
            it++;
        }
        auto begin = it;
        while (*it != ' ' && it != word.end()) {
            it++;
        }
        auto end = it;
        reverse(begin, end);
    }
    return word;
}

