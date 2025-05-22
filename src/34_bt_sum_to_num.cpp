//
// Created by Damon on 2025/5/22.
//

#include "my_algorithms.h"

using namespace std;

void FindValidPath(TreeNode* head, std::vector<std::vector<int>>& paths, int target, vector<int>& curPath)
{
    curPath.push_back(head->value);
    int resNum = target - head->value;
    // 如果总数能对，则将当前的结果放入返回值中
    if (target - head->value == 0) {
        paths.push_back(curPath);
    }
    if (head->left) {
        FindValidPath(head->left, paths, resNum, curPath);
    }
    if (head->right) {
        FindValidPath(head->right, paths, resNum, curPath);
    }
    curPath.pop_back();
}

std::vector<std::vector<int>> TreeNodeSumTrace(TreeNode* head, int sum)
{
    if (head == nullptr) {
        return {};
    }
    std::vector<std::vector<int>> paths;
    vector<int> curPath;
    FindValidPath(head, paths, sum, curPath);
    return paths;
}
