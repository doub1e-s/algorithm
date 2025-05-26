//
// Created by Damon on 2025/5/26.
//

#include "my_algorithms.h"

void ReorderHelper(string& str, int index, vector<string>& res)
{
    if (index == str.size() - 1) {
        res.push_back(str);
    }
    for (int i = index; i < str.size(); i++) {
        swap(str[i], str[index]);
        ReorderHelper(str, index + 1, res);
        swap(str[i], str[index]);
    }
}

vector<string> ReorderString(string str)
{
    vector<string> res;
    ReorderHelper(str, 0, res);
    return res;
}
