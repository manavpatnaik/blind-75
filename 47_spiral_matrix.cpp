#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;
    vector<int> res;
    int direction = 1;
    
    while (left <= right && top <= bottom) {
        if (direction == 1) {
            // top row
            for (int i = left; i <= right; i++) 
                res.push_back(matrix[top][i]);
            top++;
            direction = 2;
        } else if (direction == 2) {
            // right column
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;
            direction = 3;
        } else if (direction == 3) {
            // bottom row
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
            direction = 4;
        } else {
            // left column
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
            direction = 1;
        }
    }
    
    return res;
}