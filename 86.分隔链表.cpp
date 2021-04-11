/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    // 手动模拟一遍，就能出答案，简单题
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(), rh = new ListNode();
        auto lt = lh, rt = rh;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) lt = lt->next = p;
            else rt = rt->next = p;
        }
        lt->next = rh->next;
        rt->next = nullptr;
        return lh->next;
    }
};
// @lc code=end

