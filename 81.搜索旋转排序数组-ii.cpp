/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 * 
 * 即使用二分，最坏情况下还是 O(N)
 * 譬如数据为[1,1,1,1,1,1,1,1,1,1,0]
 */

// @lc code=start

// 不要和面试官撕逼，如果不满意，老老实实写二分
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) return 1;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
                
        int l = 0, r = nums.size() - 1;
        while (r && nums[l] == nums[r]) r--; // 去重，这里极端状态下退化成 O(N)。所以还不如直接遍历
        if (r == 0) return nums[r] == target;

        while (l < r) { // 二分划分为两个区间
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[0]) l = 0;
        else l = r + 1, r = nums.size() - 1;

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[r] == target;
    }
};
// @lc code=end

