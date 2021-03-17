/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& cs, int t) {
        dfs(0, cs, t);
        return res;
    }

    void dfs (int u, vector<int>& cs, int t) {
        if (t == 0) {
            res.push_back(path);
            return;
        }
        if (u == cs.size()) return;
        for (int i = 0; cs[u] * i <= t; i++) {
            dfs (u + 1, cs, t - cs[u] * i);
            path.push_back(cs[u]);
        }
        for (int i = 0; cs[u] * i <= t; i++) {
            path.pop_back();
        }
    }
};
// @lc code=end

