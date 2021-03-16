/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 * 
 * 最优解马拉车 O(N)，太难略
 * 本做法 O(N^2)，简单
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            // 奇数回文串
            int l = i - 1, r = i + 1;
            while (l >= 0 && r <= s.size() && s[l] == s[r])  l--, r++;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
            // 偶数回文串
            l = i, r = i + 1;
            while (l >= 0 && r <= s.size() && s[l] == s[r])  l--, r++;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};
// @lc code=end

