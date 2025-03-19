//
// Created by Damon on 2025/3/19.
//

#include "my_algorithms.h"

void MyQueue::Push(int value)
{
    m_insertStack.push(value);
}

void MyQueue::Pop()
{
    if (m_popStack.empty()) {
        // 如果m_insertStack也是空的，先不处理
        while (!m_insertStack.empty()) {
            m_popStack.push(m_insertStack.top());
            m_insertStack.pop();
        }
    }
    m_popStack.pop();
}

int MyQueue::Top()
{
    if (m_popStack.empty()) {
        // 如果m_insertStack也是空的，先不处理
        while (!m_insertStack.empty()) {
            m_popStack.push(m_insertStack.top());
            m_insertStack.pop();
        }
    }
    return m_popStack.top();
}
