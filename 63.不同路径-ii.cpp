/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size(), n = o[0].size();
        if (!m || o[0][0]) return 0; // leetcode 特色
        vector<vector<int>> f(m, vector<int> (n));
        f[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!o[i][j]) {
                    if (i) f[i][j] += f[i - 1][j];
                    if (j) f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
// @lc code=end