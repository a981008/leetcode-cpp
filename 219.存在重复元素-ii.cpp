/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (h.count(nums[i])) {
                if (i - h[nums[i]] <= k) return true;
                h[nums[i]] = i;
            } else {
                h.insert({nums[i], i});
            }
        }
        return false;
       
    }
};
// @lc code=end

