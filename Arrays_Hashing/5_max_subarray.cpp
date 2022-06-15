#include <bits/stdc++.h>
using namespace std;

// Kadane's algo
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currSum = 0;
    for (int num : nums) {
        if (currSum + num >= num) currSum += num;
        else currSum = num;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}