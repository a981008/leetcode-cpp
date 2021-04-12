/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto p = dummy;
        for (int i = 0; i < left - 1; i++) p = p->next;
        auto q = p->next, r = q->next;
        for (int i = 0; i < right - left; i++) {
            auto s = r->next;
            r->next = q;
            q = r, r = s;
        }
        p->next->next = r;
        p->next = q;
        return dummy->next;
    }
};
// @lc code=end

