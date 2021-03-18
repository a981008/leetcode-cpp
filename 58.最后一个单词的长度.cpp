/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int j = i - 1;
                while (j >= 0 && s[j] != ' ') j--;
                return i - j;
            }
        }
        return 0;
    }
};
// @lc code=end

