//
// Created by Damon on 2025/4/10.
//

#include "my_algorithms.h"

/**
 * 解题思路上，按照位进行递归，从左往右，每一轮递归都使用for循环保证该位确定值之后，能够将剩余的每一个数字都打印。
 * 返回值上，需要注意，index符合要求后直接插入返回数组，并直接return，优先判断是否满足return条件
 */

std::string DeleteBeginZero(const std::string& num)
{
    /* 原始写法，不优雅
    std::string afterNum = num;
    if (afterNum.empty()) { return afterNum; }
    while (*afterNum.begin() == '0') {
        afterNum.erase(afterNum.begin());
    }
    if (afterNum.empty()) { afterNum.push_back('0'); }
    return afterNum;
    */

    size_t firstNonZero = num.find_first_not_of('0');
    if (firstNonZero == std::string::npos) {
        return "0";
    }
    return num.substr(firstNonZero);
}

void GenerateStrings(std::string& num, int index, int maxIndex, std::vector<std::string>& nums)
{
    // 等于index的时候直接返回，相当于从下标0开始向外输出数字
    if (index == maxIndex) {
        std::string insertNum = DeleteBeginZero(num);
        nums.push_back(insertNum);
        return ;    // 这里应该要直接返回，不然过多
    }
    for (char c = '0'; c <= '9'; c++) {
        num[index] = c;
        GenerateStrings(num, index + 1, maxIndex, nums);
    }
}

std::vector<std::string> GetAllNumSinceOneToMaxN(int n)
{
    if (n <= 0) { return {}; }
    std::string num(n, '0');
    std::vector<std::string> result;
    GenerateStrings(num, 0, n, result);
    return result;
}
