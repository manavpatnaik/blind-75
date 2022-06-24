#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<vector<char>> &grid, int row, int col, int m, int n) {
    if (row < 0 || col < 0 || col >= n || row >= m || grid[row][col] == '0') return;
    
    grid[row][col] = '0';
    
    dfsUtil(grid, row+1, col, m, n);
    dfsUtil(grid, row-1, col, m, n);
    dfsUtil(grid, row, col+1, m, n);
    dfsUtil(grid, row, col-1, m, n);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfsUtil(grid, i, j, m, n);
            }
        }
    }
    return count;
}