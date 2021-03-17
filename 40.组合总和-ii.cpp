/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& cs, int t) {
        sort(cs.begin(), cs.end());
        dfs(0, cs, t);
        return res;
    }

    void dfs (int u, vector<int>& cs, int t) {
        if (t == 0) {
            res.push_back(path);
            return;
        }
        if (u == cs.size()) return;
        int k = u + 1;
        while (k < cs.size() && cs[k] == cs[u]) k++;
        int cnt = k - u;
        for (int i = 0; cs[u] * i <= t && i <= cnt; i++) {
            dfs (k, cs, t - cs[u] * i);
            path.push_back(cs[u]);
        }
        for (int i = 0; cs[u] * i <= t && i <= cnt; i++) {
            path.pop_back();
        }
    }
};
// @lc code=end

