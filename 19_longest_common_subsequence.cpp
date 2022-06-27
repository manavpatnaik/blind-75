#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    int dp[m+1][n+1];
    
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = m-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }