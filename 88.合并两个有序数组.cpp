/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    // 二路贵宾，手动模拟就能出答案，注意要从后往前遍历，防止覆盖
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            a[k--] = a[i] > b[j] ? a[i--] : b[j--];
        }
        while (j >= 0) {
            a[k--] = b[j--];
        }
    }
};
// @lc code=end

