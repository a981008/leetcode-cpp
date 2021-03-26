/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
     int hIndex(vector<int>& citations) {
        int n = citations.size();
        int papers[n + 1];
        memset(papers, 0, sizeof papers);
        // 计数
        for (int c: citations) papers[min(n, c)]++;
        // 找出最大的 k
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k]) k--;
        return k;
    }
};
// @lc code=end

