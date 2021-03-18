/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<bool> col, dg, udg;
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        col = dg = udg = vector<bool> (2 * n);
        path = vector<string> (n, string(n, '.'));
        dfs(0, n);
        return res;
    }
    void dfs(int u, int n) {
        if (u == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = 1;
                path[u][i] = 'Q';
                dfs(u + 1, n);
                col[i] = dg[u - i + n] = udg[u + i] = 0;
                path[u][i] = '.';
            }
        }
    }
};
// @lc code=end

