/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode();
        auto p = dummy;
        dummy->next = head;
        while (p->next) {
            auto q = p->next->next;
            while (q && q->val == p->next->val) 
                q = q->next;
            if (p->next->next == q) p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};
// @lc code=end

