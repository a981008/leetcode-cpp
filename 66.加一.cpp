/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        reverse(d.begin(), d.end());
        int r = 1;
        for (int i = 0; i < d.size(); i++) 
            r += d[i], d[i] = r % 10, r /= 10;
        if (r) d.push_back(r);
        reverse(d.begin(), d.end());
        return d;
    }
};
// @lc code=end

