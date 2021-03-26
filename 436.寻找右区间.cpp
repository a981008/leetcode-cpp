/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& q) {
        int n = q.size();
        for (int i = 0; i < n; i++) q[i].push_back(i);
        sort(q.begin(), q.end());
        vector<int> res(n, -1);
        for (auto& x: q) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (q[mid][0] >= x[1]) r = mid;
                else l = mid + 1;
            }
            if (q[r][0] >= x[1]) res[x[2]] = q[r][2];
        }
        return res;
    }
};
// @lc code=end

