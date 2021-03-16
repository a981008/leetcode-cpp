/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int map[256];
        map['I'] = 1, map['V'] = 5;
        map['X'] = 10, map['L'] = 50;
        map['C'] = 100, map['D'] = 500;
        map['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && map[s[i + 1]] > map[s[i]]) 
                res -= map[s[i]];
            else res += map[s[i]];
        }
        return res;
    }
};
// @lc code=end

