/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * 
 * 括号匹配成立的充要条件
 * 1. 前缀中左括号数量 > 右括号数量
 * 2. 左右括号数量相等
 * 
 * 扩展：如果只求匹配成功方案的数量，则是卡特兰数
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string path) {
        if (lc == n && rc == n) res.push_back(path);
        else {
            if (lc < n) dfs(n, lc + 1, rc, path + '(');
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, path + ')');
        }
    }
};
// @lc code=end

