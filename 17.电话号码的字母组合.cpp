/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return res;
        dfs(digits, 0, "");
        return res;
    }
    void dfs(string &digits, int i, string path) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : strs[digits[i] - '0']) 
        dfs(digits, i + 1, path + c);
    }
};
// @lc code=end

