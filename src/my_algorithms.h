//
// Created by Damon on 2025/3/9.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stack>
#include <string>
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

// 05 将空格替换成指定字符
void ReplaceBlank(std::string& src);

// 06 从尾到头打印链表,两种写法
struct ListNode
{
    ListNode* m_pNext;
    int m_value;
};

// 使用栈
std::vector<int> TraverseListFromEnd(const ListNode* head);

// 使用递归
void TraverseListFromEnd(const ListNode* head, std::vector<int>& result);

struct TreeNode
{
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
    int m_value;
    explicit TreeNode(const int value)
    {
        m_pLeft = nullptr;
        m_pRight = nullptr;
        m_value = value;
    }
};

// 07 重建二叉树
TreeNode* ReBuildBinaryTree(std::vector<int>& preOrder, std::vector<int>& inOrder);

// 09 用栈实现一个队列
class MyQueue
{
public:
    void Push(int value);
    int Top();
    void Pop();
    std::stack<int> m_insertStack;
    std::stack<int> m_popStack;
};

// 10 斐波那契数列
int Fibonacci(int n);
int FibonacciByVec(int n);

// 11 找到旋转数组中的最小值
int FindMinInSpinVec(std::vector<int>& vec);

// 12 矩阵中的路径
bool FindExistPath(const std::vector<std::vector<char>>& matrix, const std::string& target);

// 13 机器人运动范围
int RobotMoveRange(int rowBound, int colBound, int k);

// 14 剪绳子
int CutRope(int k);

// 15 二进制1个数
int Count1Times(int value);

// 16 数值的整数次方
double GetPower(int value, int exponent);




#endif //ALGORITHMS_H