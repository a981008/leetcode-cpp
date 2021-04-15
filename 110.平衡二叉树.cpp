/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 平衡二叉树定义
    // 1. 左右子树高度差不超过 1
    // 2. 左右子树都是平衡二叉树
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    // 用 -1 标记是否为平衡二叉树
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        // 子树中有一个不是平衡二叉树，整个树都不是平衡二叉树
        if (left == -1 || right == -1) return -1; 
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};
// @lc code=end

