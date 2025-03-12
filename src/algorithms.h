//
// Created by Damon on 2025/3/9.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string.h>

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

#endif //ALGORITHMS_H