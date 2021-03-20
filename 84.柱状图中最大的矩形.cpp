/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 * 
 * 单调栈
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int n = h.size();
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && h[i] < h[stk.top()]) {
                int top = stk.top();
                stk.pop();
                res = max(res,h[top] * (stk.empty() ? i : (i - stk.top() -1)));
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

