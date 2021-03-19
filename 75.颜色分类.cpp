/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * 
 * [75] 颜色分类
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1, r = nums.size(), i = 0; 
        while (i < r) {
            if (nums[i] < 1) swap(nums[i++], nums[++l]);
            else if (nums[i] > 1) swap(nums[i], nums[--r]);
            else i++;
        }
    }
};
// @lc code=end

