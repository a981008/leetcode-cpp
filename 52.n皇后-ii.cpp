/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    vector<bool> col, dg, udg;
    int totalNQueens(int n) {
        col = dg = udg = vector<bool> (2 * n);
        return dfs(0, n);
    }
    int dfs(int u, int n) {
        if (u == n) return 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = 1;
                res += dfs(u + 1, n);
                col[i] = dg[u - i + n] = udg[u + i] = 0;
            }
        }
        return res;
    }
};
// @lc code=end

