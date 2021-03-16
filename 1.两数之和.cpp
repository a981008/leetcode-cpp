/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * unordered_map 哈希表
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (map.count(r)) {
                return {map[r], i};
            } else {
                map[nums[i]] = i;
            }
            /* code */
        }
        return {-1, -1};
    }
};
// @lc code=end

