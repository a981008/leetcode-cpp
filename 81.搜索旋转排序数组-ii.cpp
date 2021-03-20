/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 * 
 * 即使用二分，最坏情况下还是 O(N)
 * 譬如数据为[1,1,1,1,1,1,1,1,1,1,0]
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return 1;
        }
        return 0;
    }
};
// @lc code=end

