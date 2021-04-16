/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // 分情况讨论
    // 1. 空节点 0
    // 2. 有节点
    //  (1) 左右都有，左右最小深度加上自己
    //  (2) 有左无右，左树最小深度加上自己
    //  (3) 有右无左，右树最小深度加上自己
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left) return minDepth(root->left) + 1;
        return minDepth(root->right) + 1;
    }
};
// @lc code=end

