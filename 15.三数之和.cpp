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
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) r--;
                else if (sum < 0) l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    //去重处理
                    do{l++;} while(l < r && nums[l] == nums[l - 1]);
                    do{r--;} while(l < r && nums[r] == nums[r + 1]);
                }  
            }
        }
        return res;
    }
};
// @lc code=end

