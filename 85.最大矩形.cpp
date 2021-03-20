/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 * 
 * DP + 双指针
 * 
 * 降维打击：一行一行的按照柱状图去考虑
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 0 0
 * 4*4 矩阵看成 4 个柱状图，然后求柱状图的最大矩形
 * 第一行：1 0 1 0 0
 * 第二行：2 0 2 1 1
 * 第三行：3 1 3 2 2
 * 第四行：1 0 0 0 0
 * 将矩阵转换为一个柱状图数组，只需要简单的 DP
 * 当 f[i][j] 不是 0 的时候，f[i][j] = f[i-1][j] + 1
 * 当 f[i][j] 是 0 的时候，f[i][j] = 0
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> h(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') h[i][j] = i > 0 ? h[i - 1][j] + 1 : 1;
            }
            res = max(res, largestRectangleArea(h[i]));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int n = h.size();
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && h[i] < h[stk.top()]) {
                int top = stk.top();
                stk.pop();
                res = max(res,h[top] * (stk.empty() ? i : (i - stk.top() -1)));
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

