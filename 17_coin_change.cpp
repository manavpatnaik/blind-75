#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    
    for (int amt = 1; amt < dp.size(); amt++) {
        for (int c : coins) {
            if (amt-c >= 0)
                dp[amt] = min(dp[amt], 1 + dp[amt-c]);
        }
    }
    if (dp[amount] == (amount+1)) return -1;
    return dp[amount];
}