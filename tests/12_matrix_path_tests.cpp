//
// Created by Damon on 2025/3/26.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(PathInMatrix, EmptyTest)
{
    std::vector<std::vector<char>> matrix;
    matrix.push_back({'a', 'b', 'c', 'd'});
    matrix.push_back({'e', 'f', 'g', 'h'});
    matrix.push_back({'i', 'j', 'k', 'l'});
    matrix.push_back({'m', 'n', 'o', 'u'});
    std::string target = "";
    bool res = FindExistPath(matrix, target);
    EXPECT_EQ(res, true);

    matrix.clear();
    target = "damon";
    res = FindExistPath(matrix, target);
    EXPECT_EQ(res, false);
}

TEST(PathInMatrix, SuccessTest)
{
    std::vector<std::vector<char>> matrix;
    matrix.push_back({'a', 'b', 'c', 'd'});
    matrix.push_back({'e', 'f', 'g', 'h'});
    matrix.push_back({'i', 'j', 'k', 'l'});
    matrix.push_back({'m', 'n', 'o', 'u'});
    std::string target = "aeijn";
    bool res = FindExistPath(matrix, target);
    EXPECT_EQ(res, true);
}

TEST(PathInMatrix, FailedTest)
{
    std::vector<std::vector<char>> matrix;
    matrix.push_back({'a', 'b', 'c', 'd'});
    matrix.push_back({'e', 'f', 'g', 'h'});
    matrix.push_back({'i', 'j', 'k', 'l'});
    matrix.push_back({'m', 'n', 'o', 'u'});
    std::string target = "aeimjn";
    bool res = FindExistPath(matrix, target);
    EXPECT_EQ(res, false);
}