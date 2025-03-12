//
// Created by Damon on 2025/3/11.

#include "algorithms.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

class CMyStringTest : public ::testing::Test
{
    protected:
    CMyString my_string_;
};

TEST_F(CMyStringTest, DefaultConstructor) {
    CMyString str;
    EXPECT_EQ(str.m_pData, nullptr);
}

TEST_F(CMyStringTest, ParameterizedConstructor) {
    int strLen = 14;
    char* testData = new char[strLen];
    strcpy(testData, "Hello, World!");
    CMyString str(testData, strLen);
    EXPECT_EQ(strcmp(str.m_pData, testData), 0);
}

TEST_F(CMyStringTest, CopyConstructor) {
    char* testData = new char[14];
    strcpy(testData, "Hello, World!");
    CMyString str1(testData, 14);
    CMyString str2(str1);
    EXPECT_EQ(strcmp(str1.m_pData, str2.m_pData), 0);
}

TEST_F(CMyStringTest, AssignmentOperator) {
    char* testData1 = new char[14];
    strcpy(testData1, "Hello, World!");
    CMyString str1(testData1, 14);
    CMyString str2 = str1;
    EXPECT_EQ(strcmp(str1.m_pData, str2.m_pData), 0) << "is good";
    char* testData2 = new char[16];
    strcpy(testData2, "Hello, World!");
    str2 = CMyString(testData2, 16);
    EXPECT_EQ(strcmp(str1.m_pData, str2.m_pData), 0) << "is good";
}

TEST_F(CMyStringTest, Destructor)
{
    char* testData = new char[14];
    strcpy(testData, "Hello, World!");
    {
        CMyString str(testData, 14);
    } // str goes out of scope and should be destroyed
    // No specific test here, but you can use tools like
}