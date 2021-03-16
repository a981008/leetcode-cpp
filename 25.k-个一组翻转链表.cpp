/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 * 
 * 1. 组内指向翻转
 * 2. 组头、组尾指对
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto p = dummy;
        while(true) {
            auto q = p;
            for (int i = 0; i < k && q; i++) q = q ->next;
            if (!q) break;
            auto a = p->next, b = a->next;
            for (int i = 0; i < k - 1; i++) {
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }
            auto c = p->next;
            p->next = a, c->next = b;
            p = c;
        }
        return dummy->next;
    }

};
// @lc code=end

