/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 二叉搜索树中序遍历是升序
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
    long pre = LLONG_MIN;
    bool dfs(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = dfs(root->left);
        if (pre >= root->val) {
            return false;
        }
        pre = root->val;
        bool right = dfs(root->right);
        if (pre < root->val) {
            return false;
        }
        return left && right;
    }
};
// @lc code=end

