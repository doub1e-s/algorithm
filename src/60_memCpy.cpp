//
// Created by Damon on 2025/6/29.
//

#include "my_algorithms.h"

// 实现一个memcpy函数，要求逐字节或者逐字长拷贝
int MemCopyByBytes(void* dest, const void* src, size_t count)
{
    if (dest == nullptr || src == nullptr || count == 0) {
        return -1;
    }
    if (dest == src) {
        return 0;
    }
    uintptr_t destPtr = (uintptr_t) dest;
    uintptr_t srcPtr = (uintptr_t) src;
    for (size_t i = 0; i < count; i++) {
        char* destCh = reinterpret_cast<char*>(destPtr + i);
        char* srcCh = reinterpret_cast<char*>(srcPtr + i);
        *destCh = *srcCh;
    }
    return count;
}

int MemCopyByWordLen(void* dest, const void* src, size_t count)
{
     if (dest == nullptr || src == nullptr || count == 0) {
        return -1;
    }
    if (dest == src) {
        return 0;
    }
    size_t wordLen = sizeof(void*);
    size_t wordCount = count / wordLen;
    for (size_t i = 0; i < wordCount; i++) {
        void** destVoidP = reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(dest) + i * wordLen);
        void** srcVoidP = reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(src) + i * wordLen);
        *destVoidP = *srcVoidP;
    }
    size_t leftChCount = count % wordLen;
    for (size_t i = 0; i < leftChCount; i++) {
        char* destCh = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(dest) + i);
        char* srcCh = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(src) + i);
        *destCh = *srcCh;
    }
    return count;
}

