/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        long long y = x, res = 0;
        while (y) res = res * 10 + y % 10, y /= 10;
        return res == x;
    }
};
// @lc code=end

