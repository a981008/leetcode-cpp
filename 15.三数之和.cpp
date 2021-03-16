/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int l = i + 1, r = nums.size() - 1; l < r; l++) {
                if (l > i + 1 && nums[l] == nums[l - 1]) continue;
                while (l < r - 1 && nums[i] + nums[l] + nums[r] > 0) r--;
                if (nums[i] + nums[l] + nums[r] == 0) 
                    res.push_back({nums[i], nums[l], nums[r]});
            }
        }
        return res;
    }
};
// @lc code=end

