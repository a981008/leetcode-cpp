/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * 
 * 一对括号的 ASCII 码相差不超过 2
 * 40 ( 41 )
 * 91 [ 93 ]
 * 123 { 125 }
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return 0;
            }
        }
        return !stk.size();
    }
};
// @lc code=end

