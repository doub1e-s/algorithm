//
// Created by Damon on 2025/3/9.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string.h>
#include <vector>

// 01 自定义赋值运算符函数
class CMyString
{
public:
    CMyString()
    {
        m_pData = nullptr;
        m_length = 16;
    }
    explicit CMyString(char* p_Data, int length)
    {
        if (p_Data != nullptr && length > 0) {
            m_pData = p_Data;
            m_length = length;
        } else {
            m_pData = nullptr;
            m_length = 16;
        }
    }

    CMyString(const CMyString& str)
    {
        char* copyData = new char[str.m_length];
        memcpy(copyData, str.m_pData, str.m_length);
        m_length = str.m_length;
        m_pData = copyData;
    }

    ~CMyString()
    {
        delete [] m_pData;  // 因为这里的m_pData是一个数组，所以使用delete []
    }
    CMyString& operator=(const CMyString& str);

public:
    char* m_pData;
    int m_length;
};

// 02 实现一个单例模式
class MySingleton
{
// a lot of methods are omitted here
public:
    static MySingleton& GetInstance();
    bool operator==(const MySingleton& other) const // 函数的声明一定要一致，不能少任何一个const
    {
        return true;    // 方便测试
    }
private:
    MySingleton() = default;  // 私有化构造函数
};

// 03 找到数组中的任意一个重复数字
int FindRepetitionNumber(const std::vector<int>& vec);

// 04 在二维数组中查找是否有指定的数字，每一行从左到右递增，从上到下递增
bool FindNumberInMatrix(const std::vector<std::vector<int>>& matrix, int target);

#endif //ALGORITHMS_H