/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> board;
    string word;

    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(0, i, j)) return true;
            }
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    bool dfs(int u, int x, int y) {
        if (word[u] != board[x][y]) return false;
        if (u == word.size() - 1) return true;

        char t = board[x][y];
        board[x][y] = '.'; // 标记已使用
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if (dfs(u + 1, a, b)) return true;
        }
        board[x][y] = t; // 还原现场
        return false;
    }

};
// @lc code=end

