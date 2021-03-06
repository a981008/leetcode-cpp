/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    
    vector<vector<int>> permute(vector<int>& nums) {
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
                st[i] = 1;
                path[u] = nums[i];
                dfs(nums, u + 1);
                st[i] = 0;
            }
        }
    }
};
// @lc code=end

