//
// Created by Damon on 2025/4/10.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

using namespace std;

// 自定义比较函数，用于比较两个 std::vector<std::string> 是否相等
bool AreStringVectorsEqual(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    for (size_t i = 0; i < vec1.size(); ++i) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }
    return true;
}

TEST(PrintAllNumbersTests, ZeroCheck) {
    std::vector<std::string> result = GetAllNumSinceOneToMaxN(0);
    EXPECT_EQ(result.size(), 0);
}

TEST(PrintAllNumbersTests, OneDigit) {
    std::vector<std::string> result = GetAllNumSinceOneToMaxN(1);
    std::vector<std::string> expected = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    EXPECT_TRUE(AreStringVectorsEqual(expected, result));
}

TEST(PrintAllNumbersTests, NormalTest)
{
    std::vector<std::string> funcResult = GetAllNumSinceOneToMaxN(2);
    std::vector<std::string> target;
    for (char c = '0'; c <= '9'; c++) {
        std::string str(1, c);
        target.push_back(str);
    }
    for (char ten = '1'; ten <= '9'; ten++) {
        for (char units = '0'; units <= '9'; units++) {
            string tenStr(1, ten);
            string unitsStr(1, units);
            tenStr = tenStr + unitsStr;
            target.push_back(tenStr);
        }
    }
    EXPECT_TRUE(AreStringVectorsEqual(funcResult, target));
}
