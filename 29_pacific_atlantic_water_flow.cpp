#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, set<pair<int, int>> &visit, int prevHeight, 
            vector<vector<int>> &heights, int ROWS, int COLS) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit.count({r, c}) > 0 
        || heights[r][c] < prevHeight) return;
    visit.insert({r, c});
    dfs(r+1, c, visit, heights[r][c], heights, ROWS, COLS);
    dfs(r-1, c, visit, heights[r][c], heights, ROWS, COLS);
    dfs(r, c+1, visit, heights[r][c], heights, ROWS, COLS);
    dfs(r, c-1, visit, heights[r][c], heights, ROWS, COLS);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int ROWS = heights.size(), COLS = heights[0].size();
    vector<vector<int>> res;
    set<pair<int, int>> pac, atl;
    
    for (int c = 0; c < COLS; c++) {
        dfs(0, c, pac, heights[0][c], heights, ROWS, COLS);
        dfs(ROWS-1, c, atl, heights[ROWS-1][c], heights, ROWS, COLS);
    }
    
    for (int r = 0; r < ROWS; r++) {
        dfs(r, 0, pac, heights[r][0], heights, ROWS, COLS);
        dfs(r, COLS-1, atl, heights[r][COLS-1], heights, ROWS, COLS);
    }
    
    for (auto it : pac) {
        if (atl.count(it) > 0)
            res.push_back({it.first, it.second});
    }
    
    return res;
}