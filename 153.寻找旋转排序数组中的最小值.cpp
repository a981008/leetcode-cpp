/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid; else r = mid - 1;
        }

        int res = nums[l];
        if (l) res = min(res, nums[l - 1]);
        if (l <= n - 2) res = min(res, nums[l + 1]);
        return res;
    }
};
// @lc code=end

