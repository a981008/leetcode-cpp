/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 按对角线反转
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) 
                swap(matrix[i][j], matrix[j][i]);
        }

        // 按左右反转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) 
                swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
};
// @lc code=end

