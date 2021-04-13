/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set h(nums.begin(), nums.end());
        int res = 0;
        for (auto x : nums) {
            if (h.count(x) && !h.count(x - 1)) { // 保证是每个区间的第一个开始枚举
                int len = 0;
                while (h.count(x++)) len++;
                res = max(res, len);
            }
        }
        return res;
    }
};
// @lc code=end

