/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (j < 2 || nums[i] != nums[j - 1] || nums[i] != nums[j - 2])
                nums[j++] = nums[i];
        }
        return j;
    }
};
// @lc code=end

