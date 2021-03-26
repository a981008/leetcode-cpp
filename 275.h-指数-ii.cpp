/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size(), l = 0, r = n - 1;
        if(n == 0 || c[r] == 0) return 0;
        while(l < r) {
            int mid = l + r >> 1;
            if(c[mid] >= n - mid) r = mid; else l = mid + 1;
        }
        return n - l;  
    }
};
// @lc code=end

