/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }

    void dfs(int n, vector<int>& nums) {
        if (n == nums.size()) {
            res.push_back(path);
            return;
        }
        // 要
        path.push_back(nums[n]);
        dfs (n + 1, nums);
        path.pop_back();
        // 去重
        while (n < nums.size() - 1 && nums[n] == nums[n + 1]) n++;
        // 不要
        dfs(n + 1, nums);
    }
};
// @lc code=end

