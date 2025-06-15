//
// Created by Damon on 2025/3/9.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stack>
#include <string>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int value;
    explicit TreeNode(const int value) : value(value)
    {
        left = nullptr;
        right = nullptr;
    }
    bool operator == (const TreeNode& other) const{
        return value == other.value && left == other.left && right == other.right;
    }
};

struct ListNode
{
    ListNode* next;
    int value;
    ListNode(int value) :value(value), next(nullptr) {}
    ListNode() : next(nullptr), value(0) {}
    ListNode(ListNode* pNext, int value) :next(pNext), value(value) {}
};

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
// 使用栈
std::vector<int> TraverseListFromEnd(const ListNode* head);

// 使用递归
void TraverseListFromEnd(const ListNode* head, std::vector<int>& result);


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

// 17 打印从1到最大n位数
std::vector<std::string> GetAllNumSinceOneToMaxN(int n);

// 18 删除链表中的节点
void DeleteListNode(ListNode** node, ListNode** deleteTarget);


// 21 调整数组顺序
using Predict = std::function<bool(int)>;
void AdjustArrayOrder(std::vector<int>& vec, Predict predict);

// 22 链表中倒数第k个节点
ListNode* GetLastKNode(ListNode* head, int k);

// 23 获取环状结点的首节点
ListNode* GetLoopLinkListEntryNode(ListNode* head);

// 24 反转链表
ListNode* RevertLinkList(ListNode* head);

// 25 合并两个有序链表
ListNode* Merge(ListNode* list1, ListNode* list2);

// 26 判断b树是否为a树的子结构
bool IsSubTree(TreeNode* node1, TreeNode* node2);

// 27 原地返回二叉树的镜像
TreeNode* MirrorTreeNode(TreeNode* head);

// 28 对称的二叉树
bool SymmertricTree(TreeNode* head);

// 30 构建一个包含min stack的类
template <typename T>
class MinStack
{
private:
    std::stack<T> m_stack;
    std::stack<T> m_minStack;
public:
    void Push(const T& value)
    {
        if (m_minStack.empty() || value <= m_minStack.top()) {
            m_minStack.push(value);
        }
        m_stack.push(value);
    }
    void Pop()
    {
        if (m_stack.top() == m_minStack.top()) {
            m_minStack.pop();
        }
        m_stack.pop();
    }
    T Top()
    {
        return m_stack.top();
    }
    T MinValue()
    {
        return m_minStack.top();
    }

};

// 31 栈的压入、弹出序列
bool IsStackSeqence(std::vector<int> pushSeq, std::vector<int> popSeq);

// 32 从上到下层序打印二叉树
std::vector<std::vector<int>> LayerOrder(TreeNode* head);

// 33 判断序列是不是二叉搜索树的后序遍历
bool BinarySearchTreePostOrder(std::vector<int> postOrder);

// 34 二叉树中和为某一值的路径
std::vector<std::vector<int>> TreeNodeSumTrace(TreeNode* head, int sum);

// 35 复制复杂二叉树
struct ComplexNode
{
    int value;
    ComplexNode* next;
    ComplexNode* sibling;
    ComplexNode(int value) : value(value), next(nullptr), sibling(nullptr) {};
    ComplexNode(int value, ComplexNode* next, ComplexNode* sibling) : value(value), next(next), sibling(sibling) {};
};
ComplexNode* CopyComplexNode(ComplexNode* head);

// 36 二叉搜索树与双向链表
TreeNode* ConvertBSTToDLL(TreeNode* root);

// 37 序列化和反序列化二叉树
string SerializeBT(TreeNode* root);

TreeNode* DeSerializeBT(string nodes);

// 38 字符串的排列
vector<string> ReorderString(string str);

// 39 数组中出现次数超过一般的数字
int GetMaxCntNumber(vector<int> nums);

// 40 数组中最小的K个数, 数字事先是没有进行排序的
vector<int> GetMinKNums(vector<int> nums, int k);

// 42 连续子数组的最大和
int GetMaxContinuousNumber(vector<int> nums);

// 43 1~n整数中1出现的次数
int CountToN1Times(int n);

// 47 max gift
int MaxGiftSum(vector<vector<int>> matrix);

// 48 最大不重复的子字符串
int GetMaxNoRepeatStr(const string& str);

// 49 判断一个数字是否是丑数，或找到第n个丑数
bool IsUglyNum(int num);
int FindXthUglyNum(int n);

// 51 数组中的逆序对
int GetReorderPairCnt(vector<int> arr);

// 52 两个链表的第一个公共节点
ListNode* FindFirstCommonNode(ListNode* l1, ListNode* l2);

// 53 在排序数组中查数字，返回他出现的次数
int FindNumInOrderedArr(const vector<int>& arr, int target);

// 54 二叉搜索数中的第K大节点
int FindLargeKNode(TreeNode* head, int k);

// 55 二叉树的深度
int BTDepth(TreeNode* root);

// 平衡二叉树
bool IsBalanceTree(TreeNode* root);

#endif //ALGORITHMS_H
