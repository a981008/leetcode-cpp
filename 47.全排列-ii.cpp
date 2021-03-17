/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                if (i && !st[i - 1] && nums[i - 1] == nums[i]) 
                    continue; // 剪枝，前一个用过了并且前一个与当前相同跳过
                st[i] = 1;
                path[u] = nums[i];
                dfs(nums, u + 1);
                st[i] = 0;
            }
        }
    }
};
// @lc code=end

