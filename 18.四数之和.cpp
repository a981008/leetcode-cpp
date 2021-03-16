/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target) r--;
                    else if (sum < target) l++;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        //去重处理
                        do{l++;} while(l < r && nums[l] == nums[l - 1]);
                        do{r--;} while(l < r && nums[r] == nums[r + 1]);
                    }
                    
                }
            }
        }
        return res;
    }
};
// @lc code=end

