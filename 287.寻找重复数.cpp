/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int l = 1, r = nums.size() -  1;
        // while (l < r) {
        //     int mid = l + r >> 1;
        //     int s = 0;
        //     for (auto x : nums) s += x >= l && x <= mid;
        //     if (s > mid - l + 1) r = mid;
        //     else l = mid + 1;
        // }
        // return l;
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
// @lc code=end

