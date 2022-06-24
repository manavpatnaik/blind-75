#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ROWS, COLS;
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int idx) {
        if (idx == word.length()) return true;
        if (r < 0 || r == ROWS || c < 0 || c == COLS || 
            board[r][c] != word[idx] || board[r][c] == '*')
            return false;
        
        char temp = board[r][c];
        board[r][c] = '*';
        if (dfs(board, word, r+1, c, idx+1)) return true;
        if (dfs(board, word, r-1, c, idx+1)) return true;
        if (dfs(board, word, r, c+1, idx+1)) return true;
        if (dfs(board, word, r, c-1, idx+1)) return true;
        board[r][c] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};