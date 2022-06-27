#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    bool dp[n];
    dp[n-1] = true;
    int goal = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            dp[i] = true;
            goal = i;
        } else {
            dp[i] = false;
        }
    }
    return dp[0];
}