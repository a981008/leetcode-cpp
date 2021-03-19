// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * 斐波那契数列
 * 通项公式 = 1 / 根号5 (((1 + 根号5)/2)^n - ((1 - 根号5)/2)^n)
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // 方法一：通项公式
        // double sqrt5 = sqrt(5);
        // double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        // return (int)round(fibn / sqrt5);

        // 方法二：滚动求
        int a = 1, b = 1;
        while (--n) {
            int c = a + b;
            a = b, b = c;
        }
        return b;
    }
};
// @lc code=end

