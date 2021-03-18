/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        string c;
        for (int i = 0, r = 0; i < a.size() || i < b.size() || r; i++) {
            if (i < a.size()) r += a[i] - '0';
            if (i < b.size()) r += b[i] - '0';
            c.push_back(r % 2 + '0');
            r /= 2;
        } 
        reverse(c.begin(), c.end());
        return c;
    }
};
// @lc code=end

