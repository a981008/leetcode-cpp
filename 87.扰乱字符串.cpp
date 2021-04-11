/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:

    // 暴搜改动态规划，时间复杂度 O(n^4)
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
            
        for (int k = 2; k <= n; k++) {
            for (int i1 = 0; i1 <= n - k; i1++) {
                for (int i2 = 0; i2 <= n - k; i2++) {
                    for (int i = 1; i < k; i++) {
                        if ((dp[i1][i2][i] && dp[i1 + i][i2 + i][k - i])
                        || (dp[i1][i2 + k - i][i] && dp[i1 + i][i2][k - i]))
                            dp[i1][i2][k] = true;
                    }
                }
            }
        }

        return dp[0][0][n];
    }

    // 暴搜，时间复杂度 O(5^n)，超时
    bool violent_isScramble(string s1, string s2) {
        return dfs(s1, s2, 0, 0, s1.size());
    }
    // 以下两种情况成立
    // 1. 前半部分相同并且后半部分相同
    // 2. s1 前半部分和 s2 后半部分相同，且 s1 后半部分和 s2 前半部分相同
    bool dfs(string &s1, string &s2, int i1, int i2, int k) {
        string bs1 = s1.substr(i1, k), bs2 = s2.substr(i2, k);
        if (bs1 == bs2) return true;
        sort(bs1.begin(), bs1.end()), sort(bs2.begin(), bs2.end());
        if (bs1 != bs2) return false;

        for (int i = 1; i < k; i++) {
            if ((dfs(s1, s2, i1, i2, i) && dfs(s1, s2, i1 + i, i2 + i,  k - i))
            || (dfs(s1, s2, i1, i2 + k - i, i) && dfs(s1, s2, i1 + i, i2, k - i)))
                return true;
        }

        return false;
    }
};
// @lc code=end

