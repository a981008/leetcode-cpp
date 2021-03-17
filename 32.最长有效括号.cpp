/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        for (int i = 0, st = -1; i < s.size(); i++) {
            stack<int> stk;
            if (s[i] == '(') stk.push(i);
            else {
                if (stk.size()) {
                    stk.pop();
                    res = max(res, i - (stk.size() ? stk.top() : st));
                } else st = i;
            }
        }
        return res;
    }
};
// @lc code=end

