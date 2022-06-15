#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0, currMin = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[currMin]) currMin = i;
        profit = max(profit, prices[i]-prices[currMin]);
    }
    return profit;
}