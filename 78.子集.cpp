/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
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
        // 不要
        dfs(n + 1, nums);
    }
};
// @lc code=end

