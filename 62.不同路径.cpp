/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int> (n));
        f[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               if (i) f[i][j] += f[i - 1][j];
               if (j) f[i][j] += f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};
// @lc code=end

