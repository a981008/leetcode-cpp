/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(), tail = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) tail = tail->next = l1, l1 = l1->next;
            else tail = tail->next = l2, l2 = l2->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummy->next;
    }
};
// @lc code=end

