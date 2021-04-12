/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') f[i] += f[i - 1];
            if (i > 1) {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (t >= 10 && t <= 26) f[i] += f[i - 2];
            }
        }
        return f[n];
    }

    // 暴搜必超时
    int violent_numDecodings(string s) {
        s = ' ' + s;
        return dfs(s, s.size() - 1);
    }
    int dfs(string s, int i) {
        if (i == 0) return 1;
        int res = 0;
        if (s[i] >= '1' && s[i] <= '9') res += dfs(s, i - 1);
        if (i > 1) {
            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (t >= 10 && t <= 26) res += dfs(s, i - 2);
        }
        return res;
    }
};
// @lc code=end

