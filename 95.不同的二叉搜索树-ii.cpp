/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<vector<vector<TreeNode*>>> f;
    // 暴搜 + 记忆化搜索
    vector<TreeNode*> generateTrees(int n) {
        f = vector<vector<vector<TreeNode*>>> (n + 1, vector<vector<TreeNode*>>(n + 1));
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int left, int right) {
        if (left > right) return {nullptr};
        if (f[left][right].size()) return f[left][right];
        vector<TreeNode*> res;
        for (int i = left; i <= right; i++) {
            auto l = dfs(left, i - 1), r = dfs(i + 1, right);
            for (auto a : l) {
                for (auto b : r) {
                    auto root = new TreeNode(i);
                    root->left = a, root->right = b;
                    res.push_back(root);
                }
            }
        }
        return f[left][right] = res;
    }
};
// @lc code=end

