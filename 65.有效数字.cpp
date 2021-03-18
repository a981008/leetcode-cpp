/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 *
 * 1. 先去除行首和行尾空格；
 * 2. 行首如果有一个正负号，直接忽略；
 * 3. 如果字符串为空或只有一个'.'，则不是一个合法数；
 * 4. 循环整个字符串，去掉以下几种情况：
 *     (1) '.'或'e'多于1个;
 *     (2) '.'在'e'后面出现；
 *     (3) 'e'后面或前面为空，或者'e'前面紧跟着'.'；
 *     (4) 'e'后面紧跟着正负号，但正负号后面为空；
 * 5. 剩下的情况都合法；
 * 
 * 毫无营养，垃圾题目，懒得写。直接 CV 一份代码
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l ++ ;
        while (l <= r && s[r] == ' ') r -- ;
        if (l > r) return false;
        s = s.substr(l, r - l + 1);
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if (s.empty()) return false;

        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E'))
            return false;

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '.') {
                if (dot > 0 || e > 0) return false;
                dot ++ ;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i || i + 1 == s.size() || e > 0) return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) return false;
                    i ++ ;
                }
                e ++ ;
            } else if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
};
// @lc code=end

