/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 * 
 * 快速幂
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        double res = 1;
        bool minus = n < 0;
        for (LL k = abs(LL(n)); k; k >>= 1) {
            if (k & 1) res *= x;
            x *= x;
        }
        return minus ? 1 / res : res;
    }
};
// @lc code=end

