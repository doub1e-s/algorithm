//
// Created by Damon on 2025/3/9.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>

namespace Damon {
    class CMyString
    {
    public:
        explicit CMyString(char* p_Data = nullptr)
        {
            if (p_Data != nullptr) {
                m_pData = p_Data;
            }
            m_pData = nullptr;
        }

        CMyString(const CMyString& str) { m_pData = str.m_pData; }
        ~CMyString()
        {
            delete [] m_pData;  // 因为这里的m_pData是一个数组，所以使用delete []
        }
        CMyString& operator=(const CMyString& str);

    public:
      char* m_pData;
    };
}

#endif //ALGORITHMS_H