/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 * 
 * 木桶效应：木桶能装多少水取决于它最短的木板
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& h) {
        int res = 0;
        int i = 0, j = h.size() - 1;
        while (i <= j) {
            int m = min(h[i], h[j]);
            res = max(res, m * (j - i));
            if (h[i] < h[j]) i++;
            else j--;
        }
        return res;
    }
};
// @lc code=end

