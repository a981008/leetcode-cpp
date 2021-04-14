/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    /**
     * 二叉搜索刷中序遍历是从小到大的，所以本质是找逆序对，分以下情况
     * 1. 一个逆序对，说明是两个相邻交换
     * 2. 两个逆序对，说明是第一个逆序对的第一个数和第二个逆序对的第二个数交换
     * 如：[1, 2, 4, 3, 5, 6, 7]
     * 只有一个逆序对 [4, 3]。4 和 3 交换则还原
     * 如：[1, 6, 3, 4, 5, 2, 7]
     * 第一个逆序对 [6, 3] 第二个逆序对 [5, 2]。6 和 2 交换则还原
     * 
     * 如何空间复杂度降到 O(1)，Morris 遍历
     */
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second, *prep = nullptr;
        while (root) {
            if (!root->left) {
                if (prep && prep->val > root->val) {
                    if (!first) first = prep, second = root;
                    else second = root;
                }
                prep = root;
                root = root->right;
            } else {
                TreeNode *p = root->left;
                while (p->right && p->right != root) p = p->right;
                if (!p->right) {
                    p->right = root;
                    root = root->left;
                } else {
                    p->right = nullptr;
                    if (prep && prep->val > root->val) {
                        if (!first) first = prep, second = root;
                        else second = root;
                    }
                    prep = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }

};
// @lc code=end

