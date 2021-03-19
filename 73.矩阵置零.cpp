/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 * 
 * 用原矩阵的第 0 行元素标记子矩阵的列是否有 0
 * 用原矩阵的第 0 列元素标记子矩阵的行是否有 0
 * 用 r0 变量标记第 0 行是否有 0
 * 用 c0 变量标记第 0 列是否有 0
 * 
 * 只需要两个变量 -> 原地算法
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int r0 = 1, c0 = 1;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < m; i++) if (!matrix[0][i]) r0 = 0;
        for (int i = 0; i < n; i++) if (!matrix[i][0]) c0 = 0;
       
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) 
                if (!matrix[j][i]) matrix[0][i] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) 
                if (!matrix[i][j]) matrix[i][0] = 0;
        }

        for (int i = 1; i < m; i++) {
            if (!matrix[0][i]) 
                for (int j = 1; j < n; j++) matrix[j][i] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (!matrix[i][0])
                for (int j = 1; j < m; j++) matrix[i][j] = 0;
        }

        if (!r0) for (int i = 0; i < m; i++) matrix[0][i] = 0;
        if (!c0) for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};
// @lc code=end

