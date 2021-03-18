/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) return 0;
            j = max(i + nums[i], j);
        }
        return 1;
    }
};
// @lc code=end

