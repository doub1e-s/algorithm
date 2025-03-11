//
// Created by Damon on 2025/3/9.
//
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数

/*
首先
构造函数：构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
       可用于为某些成员变量设置初值(这个时候构造函数要带参数)
析构函数：析构函数的名称与类的名称是完全相同的，只是在前面加了个~作为前缀，它不会返回任何值，也不能带有任何参数。
        析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。在每次删除所创建的对象时执行
拷贝构造函数：一种特殊的构造函数，其在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象
重载赋值操作符函数：对赋值操作符"="进行重载，默认情况下，对于对象使用的是浅拷贝，重载赋值运算符解决了析构函数中过程中多次释放同一块内存的问题
取地址运算符：返回当前对象的地址，对于成员函数来讲，this指针就是它的地址，需要返回指针。
const修饰的取地址运算符：(与上面这个函数，不写的话编译器也会默认生成，默认返回this指针)
*/

#include <string.h>
#include <algorithms.h>
namespace Damon {
    /* 初级程序员写法，这里需要注意的是返回值需要是CMyString的引用，这样能够保证链式调用赋值运算符
    CMyString& CMyString::operator=(const CMyString& str)
    {
        if (this == &str) { // 避免赋值给自己，赋值给自己可能会导致已经删除了内存，然后又设置给自己
            return *this;
        }
        delete [] m_pData;  // 释放内存
        m_pData = new char[strlen(str.m_pData) + 1];    // 如果申请内存异常，则容易因为返回空指针导致程序crash
        strcpy(m_pData, str.m_pData);
        return *this;
    }
    */

    // 优雅的写法，使用拷贝构造函数和临时变量，保证了即是内存不够，也保证原有的对象还是能够正常使用
    CMyString& CMyString::operator=(const CMyString& str)
    {
        if (this != &str) {
            CMyString strTemp(str); // 使用拷贝构造函数在栈上创建一个相同的临时实例
            char* pTemp = strTemp.m_pData;  // 保留temp中m_pData的地址
            strTemp.m_pData = m_pData;  // 将当前对象的地址传给临时变量，以便临时变量调用析构函数时能清除内存
            m_pData = pTemp;    // 将当前的m_pData指向实际复制的那段地址
        }   // 作用域结束后，strTemp会删除旧的地址空间
        return *this;
    }
} // namespace Damon