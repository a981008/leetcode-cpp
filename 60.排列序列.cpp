/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        bool st[10] = {0};
        for (int i = 0; i < n; i ++ ) {
            int f = 1;
            for (int j = 1; j < n - i; j ++ ) f *= j;
            for (int j = 0; j < n; j ++ ) {
                if (!st[j]) {
                    if (k <= f) {
                        res += to_string(j + 1);
                        st[j] = true;
                        break;
                    }
                    k -= f;
                }
            }
        }
        return res;
    }
};
// @lc code=end

