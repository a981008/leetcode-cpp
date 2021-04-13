/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // Morris 遍历，空间复杂度 O(1)
    // 1. cur 无左，cur 右移
    // 2. cur 有左，找到 cur 左子树上最右的节点，记为 p
    //   （1）p 的 right 指针指向空，说明方向从上往下，让其指向 cur，cur 左移
    //   （2）p 的 right 指针指向 cur，说明方向从下往上，让其指向空，cur 右移
    // A B 处操作就是先序，A C 处操作就是中序
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root, *p = nullptr;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val); // A
                cur = cur->right;
            } else {
                p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (!p->right) {
                    res.push_back(cur->val); // B
                    p->right = cur;
                    cur = cur->left;
                } else {
                    // C
                    p->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end

