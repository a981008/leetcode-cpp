/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 * 
 */

// @lc code=start
class Solution {
public:
    // 卡特兰数通项公式：C0 = 1, Cn+1 = 2 * (2n + 1) / (n + 2) * Cn
    int numTrees(int n) {
        int C = 1;
        for (int i = 0; i < n; ++i) {
            C = 1L * C * 2 * (2 * i + 1) / (i + 2);
        }
        return C;
    }

    // dp
    int dp_numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i] += f[i - 1] * f[i - j];
            }
        }
        return f[n];
    }

};
// @lc code=end

