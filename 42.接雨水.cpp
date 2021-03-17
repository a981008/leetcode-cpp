/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < h.size(); i++) {
            int t = 0;
            while (stk.size() && h[i] > h[stk.top()]) {
                res += (h[stk.top()] - t) * (i - stk.top() - 1);
                t = h[stk.top()];
                stk.pop();
            }
            if (stk.size()) 
                res += (h[i] - t) * (i - stk.top() - 1);
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

