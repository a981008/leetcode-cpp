/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
       int tmap[256] = {0}, wmap[256] = {0};
       for (auto c : t) tmap[c]++;
       int cnt = 0;
       string res;
       for (int i = 0, j = 0; i < s.size(); i++) {
            wmap[s[i]]++;
            if (wmap[s[i]] <= tmap[s[i]]) cnt++;
            while (wmap[s[j]] > tmap[s[j]]) wmap[s[j++]]--;
            if (cnt == t.size() && (res.empty() || i - j + 1 < res.size()))
                res = s.substr(j, i - j + 1);
       }
       return res;
    }
};
// @lc code=end

