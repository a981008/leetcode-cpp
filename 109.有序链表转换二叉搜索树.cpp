/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // 法一：将链表转数组，用索引定位中间节点，按照 108 题做，时间复杂度 O(N) 空间复杂度 O(N)
    
    // 法二：使用快慢指针定位中间节点，按照 108 题做，时间复杂度 O(NlogN) 空间复杂度 O(logN)
    // TreeNode* sortedListToBST(ListNode* head) {
    //     return dfs(head, nullptr);
    // }
    // ListNode* getMidNode(ListNode* l, ListNode* r) {
    //     auto fast = l, slow = l;
    //     while(fast != r && fast->next != r) 
    //         fast = fast->next->next, slow = slow->next;
    //     return slow;
    // }
    // TreeNode* dfs(ListNode* l, ListNode* r) {
    //     if (l == r) return nullptr;
    //     auto mid = getMidNode(l, r);
    //     auto root = new TreeNode(mid->val);
    //     root->left = dfs(l, mid);
    //     root->right = dfs(mid->next, r);
    //     return root;
    // }

    // 法三：中序遍历建树，时间复杂度 O(N) 空间复杂度 O(logN)
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, 0, getLen(head) - 1);
    }
    int getLen(ListNode* head) {
        int len = 0;
        while (head) head = head->next, len++;
        return len;
    }
    TreeNode* dfs(ListNode* &head, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + r + 1 >> 1;
        auto root = new TreeNode();
        root->left = dfs(head, l, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = dfs(head, mid + 1, r);
        return root;
    }
};
// @lc code=end

