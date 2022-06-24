#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode() {
        isWord = false;
    }
    
    void addWord(string str) {
        TrieNode* curr = this;
        for (char ch : str) {
            if (curr->children.find(ch) == curr->children.end())
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    int ROWS, COLS;
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node, 
             string word, vector<string> &res) {
        if (r < 0 || c < 0 || r == ROWS || c == COLS || 
            node->children.find(board[r][c]) == node->children.end() || 
            board[r][c] == '*') return;
        
        node = node->children[board[r][c]];
        word += board[r][c];
        // If word is found, then remove it from the trie
        if (node->isWord) {
            res.push_back(word);
            node->isWord = false;
        }
        
        char temp = board[r][c];
        board[r][c] = '*';
        dfs(r+1, c, board, node, word, res);
        dfs(r-1, c, board, node, word, res);
        dfs(r, c+1, board, node, word, res);
        dfs(r, c-1, board, node, word, res);
        board[r][c] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) root->addWord(word);
        
        ROWS = board.size(), COLS = board[0].size();
        
        vector<string> res;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++){
                dfs(i, j, board, root, "", res);
            }
        }
        return res;
    }
};