/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 
 * 模版题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& is) {
        vector<vector<int>> res;
        if (is.empty()) return res;
        // 1. 按照左端点排序
        sort(is.begin(), is.end());
        int l = is[0][0], r = is[0][1];
        for (int i = 1; i < is.size(); i++) {
            if (r >= is[i][0]) { // 2. 有交集更新右端点
                r = max(r, is[i][1]);    
            } else { // 3. 无交集则是独立区间，保存，并切换下一个区间
                res.push_back({l, r});
                l = is[i][0], r = is[i][1];
            }
        }
        res.push_back({l, r});
        return res;       
    }
};
// @lc code=end

