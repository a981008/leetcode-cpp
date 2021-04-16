/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        if (n < m) return 0;
        if (n == m) {
            if (s == t) return 1;
            return 0;
        }

        vector<vector<long long>> f(n + 1, vector<long long> (m + 1));
        s = ' ' + s, t = ' ' + t;
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i] == t[j]) f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[n][m];
    }
};
// @lc code=end

