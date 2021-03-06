/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 * 
 * 完全背包优化
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool> (m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 2] 
                    || i && f[i - 1][j] 
                    && (s[i] == p[j - 1] || p[j-1] == '.');
                } else {
                    f[i][j] = i && f[i - 1][j - 1] 
                    && (s[i] == p[j] || p[j] == '.');
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end

