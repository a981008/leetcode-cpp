/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(nums.back() + 1);
        int l = 0, r = nums.size() / 2 - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid * 2] != nums[mid * 2 + 1]) r = mid; else l = mid + 1;
        }
        return nums[r * 2];
    }
};
// @lc code=end

