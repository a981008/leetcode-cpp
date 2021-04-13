/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<vector<bool>> f(m + 1, vector<bool> (n + 1));
        f[0][0] = true;
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i && s1[i] == s3[i + j]) f[i][j] = f[i - 1][j];
                if (j && s2[j] == s3[i + j]) f[i][j] = f[i][j] || f[i][j - 1];
            }
        }
        return f[m][n];
    }
};
// @lc code=end

