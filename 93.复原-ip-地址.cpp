/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }

    void dfs(string &s, int u, int k, string path) {
        int n = s.size();
        if (u == n) {
            path.pop_back();
            if (k == 4) res.push_back(path);
            return;
        }
        if (k == 4) return;
        for (int i = u, t = 0; i < n; i++) {
            if (i > u && s[u] == '0') break; // 前导 0
            t = t * 10 + s[i] - '0';
            if (t <= 255) dfs(s, i + 1, k + 1, path + to_string(t) + '.');
            else break;
        }

    }
};
// @lc code=end

