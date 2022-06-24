#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int left = 0, right = matrix.size()-1;
    
    while (left < right) {
        int top = left, bottom = right;
        
        // Rotate each outer layer
        for (int i = 0; i < right-left; i++) {
            int topLeft = matrix[top][left+i];
            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = topLeft;
        }
        
        // Dive into the next inner layer
        left++;
        right--;
    }
}