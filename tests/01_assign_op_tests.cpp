//
// Created by Damon on 2025/3/11.

#include "algorithms.h"
#include <gtest/gtest.h>

using namespace Damon;

class CMyStringTest : public ::testing::Test
{
    protected:
    Damon::CMyString my_string_;
};

TEST_F(CMyStringTest, DefaultConstructor) {
    CMyString str;
    EXPECT_EQ(str.m_pData, nullptr);
}

TEST_F(CMyStringTest, ParameterizedConstructor) {
    char* testData = new char[14];
    strcpy(testData, "Hello, World!");
    CMyString str(testData);
    EXPECT_EQ(strcmp(str.m_pData, testData), 0);
}

TEST_F(CMyStringTest, CopyConstructor) {
    char* testData = new char[14];
    strcpy(testData, "Hello, World!");
    CMyString str1(testData);
    CMyString str2(str1);
    EXPECT_EQ(strcmp(str1.m_pData, str2.m_pData), 0);
}

TEST_F(CMyStringTest, AssignmentOperator) {
    char* testData1 = new char[14];
    char* testData2 = new char[16];
    CMyString str1(testData1);
    CMyString str2;
    str2 = str1;
    EXPECT_EQ(strcmp(str1.m_pData, str2.m_pData), 0);

    str2 = CMyString(testData2);
    EXPECT_EQ(strcmp(str2.m_pData, testData2), 0);
}

TEST_F(CMyStringTest, Destructor)
{
    char* testData = new char[14];
    strcpy(testData, "Hello, World!");
    {
        CMyString str(testData);
    } // str goes out of scope and should be destroyed
    // No specific test here, but you can use tools like
}