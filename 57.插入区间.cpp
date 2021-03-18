/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        int i = 0, n = a.size();
        // 1. 前面无交集部分，直接添加
        while (i < n && a[i][1] < b[0]) res.push_back(a[i++]);
        // 2. 有交集部分，扩展
        if (i < n) {
            b[0] = min(b[0], a[i][0]);
            while (i < n && a[i][0] <= b[1]) b[1] = max(b[1], a[i++][1]);
        }
        res.push_back(b);
        // 3. 后面无交集部分，直接添加
        while (i < n) res.push_back(a[i++]);  
        return res;
    }
};
// @lc code=end

