/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    // 滚动数组优化
    // 机械式改法
    // 1. 总共 n 行改成 2 行
    // 2. 使用第 i % 2 行
    // % 2 相当于 & 1，且位运算比四则优先级低
    vector<int> getRow(int n) {
        vector<vector<int>> f(2, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            f[i & 1][0] = f[i & 1][i] = 1;
            for (int j = 1; j < i; j++) {
                f[i & 1][j] = f[i - 1 & 1][j - 1] + f[i - 1 & 1][j];
            }
        }
        return f[n & 1];
    }
};
// @lc code=end

