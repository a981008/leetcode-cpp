/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int k = 0;

        while (k < s.size() && s[k] == ' ') k++;
        if (k == s.size()) return 0;

        int minus = 1;
        if (s[k] == '-') minus = -1, k++;
        else if (s[k] == '+') k++;

        int res = 0;
        while(k < s.size() && s[k] >= '0' && s[k] <= '9') {
            int x = s[k] - '0';
            if (res > 0 && res > (INT_MAX - x) / 10) {
                if (minus == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = res * 10 + x;
            k++;
        }

        return res * minus;
    }
};
// @lc code=end

