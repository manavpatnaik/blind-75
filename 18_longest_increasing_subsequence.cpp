#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> dp(N, 1);
    dp[N-1] = 1;
    int maxLen = 1;
    
    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            if (nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}