/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return res;
        int m = matrix[0].size();
        int dx[] = {0, 1, 0, -1} , dy[] = {1, 0, -1, 0};
        bool st[n][m];
        memset (st, 0, sizeof st);
        for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            st[x][y] = 1;
            int a = x + dx[d], b = y + dy[d];
            // 越界纠正
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return res;
    }
};
// @lc code=end

