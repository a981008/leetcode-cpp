/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 * 递归二分 O(log(n+m))
 */

// @lc code=start
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 0) {
            int left = func(nums1, 0, nums2, 0, tot / 2);
            int right = func(nums1, 0, nums2, 0, tot / 2 + 1);
            return (left + right) / 2.0;
        } else {
            return func(nums1, 0, nums2, 0, tot / 2 + 1);
        }
    }

    int func(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // 第一个数组短
        if (nums1.size() - i > nums2.size() - j) 
            return func(nums2, j, nums1, i, k);
        // 边界处理
        if (k == 1) {
            if (nums1.size() == i) return nums2[j];
            else return min(nums1[i], nums2[j]);
        }
        if (nums1.size() == i) return nums2[j + k - 1];
        // 一般情况
        int si = min((int)nums1.size(), i + k / 2), sj = j + k - k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
            return func(nums1, i, nums2, sj, k - (sj - j));
        else
            return func(nums1, si, nums2, j, k - (si - i));
    }
};
// @lc code=end

