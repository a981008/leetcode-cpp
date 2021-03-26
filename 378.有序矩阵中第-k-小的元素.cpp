/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = INT_MIN, r = INT_MAX, n = matrix.size();
        while (l < r) {
            int mid = (long long) l + r >> 1;
            int i = 0, j = n - 1, cnt = 0;
            while (i < n) {                
                while (j >= 0 && matrix[i][j] > mid) j--;                
                i++, cnt += j + 1;
            }              
            if (cnt >= k) r = mid; else l = mid + 1;
        }
        return r;
    }
};
// @lc code=end

