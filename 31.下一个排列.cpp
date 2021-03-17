/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i && nums[i - 1] >= nums[i]) i--;
        if (i == 0) reverse(nums.begin(), nums.end());
        else {
            int j = i;
            while (j < nums.size() && nums[j] > nums[i - 1]) j++;
            swap(nums[i - 1], nums[j - 1]);
            reverse(nums.begin() + i, nums.end());     
        }
    }
};
// @lc code=end

