/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 * 
 * 原地算法：空间复杂度为 O(1)
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return j + 1;
    }
};
// @lc code=end

