/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& ws, int max) {
        vector<string> res;
        int n = ws.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1, len = ws[i].size();
            while (j < n && len + 1 + ws[j].size() <= max) len += 1 + ws[j++].size();
            string line = ws[i];
            if (j == n || j == i + 1) { // 这行只有一个单词或最后一行单词，只需要左对齐、
                for (int k = i + 1; k < j; k++) line += ' ' + ws[k];
                while (line.size() < max) line += ' ';
            } else { // 左右都对齐
                int cnt = j - i - 1, r = max - len + cnt;
                int k = 0;
                while (k < r % cnt) line += string(r / cnt + 1, ' ') + ws[i + k + 1], k++;
                while (k < cnt) line += string(r / cnt, ' ') + ws[i + k + 1], k++;
            }
            res.push_back(line);
            i = j - 1;
        }
        return res;
    }
};
// @lc code=end

