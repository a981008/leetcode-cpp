/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 * 
 * 大根堆 O(NlogK)
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
    struct Cmp {
        bool operator() (ListNode * a, ListNode * b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto dummy = new ListNode(), tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        for (auto l : lists) if (l) heap.push(l);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            tail = tail->next = t;
            if (t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};
// @lc code=end

