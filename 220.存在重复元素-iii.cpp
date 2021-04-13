/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 * 
 * 生成 k 个桶，桶内元素相减绝对值不超过 t
 */

// @lc code=start
class Solution {
public:
    typedef long long LL;
    long get_id(long x, long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<LL, LL> h;
        long w = t + 1L;
        for (int i = 0; i < nums.size(); i++) {
            long id = get_id(nums[i], w);
            if (h.count(id)) return true;
            if (h.count(id - 1) && abs(h[id - 1] - nums[i]) < w) return true;
            if (h.count(id + 1) && abs(h[id + 1] - nums[i]) < w) return true;
            h[id] = nums[i];
            if (i >= k) h.erase(get_id(nums[i - k], w));
        }
        return false;
    }
};
// @lc code=end

