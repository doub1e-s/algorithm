//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"

pair<int, int> FindTwoNumInVec(const vector<int>& vec)
{
    if (vec.empty()) { return make_pair(-1, -1); }
    // 获取所有数字异或之后的结果，用来将数组分成两类，一类是是对应位为1，另一类是对应位为0
    int xorRes = 0;
    for (int i = 0; i < vec.size(); i++) {
        xorRes = xorRes ^ vec[i];
    }
    int flag = 1;
    while ((flag & xorRes) == 0) {
        flag = flag << 1;
    }
    int zeroSide = 0;
    int oneSide = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] & flag) {
            oneSide = oneSide ^ vec[i];
        } else {
            zeroSide = zeroSide ^ vec[i];
        }
    }
    return make_pair(zeroSide, oneSide);
}

