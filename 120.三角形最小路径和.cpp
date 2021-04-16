/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& f) {
        for (int i = f.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] += min(f[i + 1][j + 1], f[i + 1][j]);
            }
        }
        return f[0][0];
    }
};
// @lc code=end

