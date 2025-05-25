//
// Created by Damon on 2025/5/25.
//

#include "my_algorithms.h"
#include <sstream>

void PreOrderSerialize(TreeNode* node, ostringstream& oss)
{
    if (!node) {
        oss << "#,";
        return ;
    }
    oss << node->value << ",";
    PreOrderSerialize(node->left, oss);
    PreOrderSerialize(node->right, oss);
}

string SerializeBT(TreeNode* root)
{
    if (root == nullptr) { return "#"; }
    ostringstream oss;
    PreOrderSerialize(root, oss);
    string res = oss.str();
    res.pop_back();
    return res;
}

TreeNode* PreDeSerializeBT(istringstream& iss)
{
    string val;
    if (!std::getline(iss, val, ',')) {
        return nullptr;
    }
    if (val == "#") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(val));
    root->left = PreDeSerializeBT(iss);
    root->right = PreDeSerializeBT(iss);
    return root;
}

TreeNode* DeSerializeBT(string nodes)
{
    istringstream iss(nodes);
    return PreDeSerializeBT(iss);
}