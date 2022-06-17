#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int res = *(max_element(nums.begin(), nums.end()));
    int currMax = 1, currMin = 1;
    
    int a, b;
    
    for (int num : nums) {
        if (num == 0) {
            currMax = currMin = 1;
            continue;
        }
        a = num*currMax;
        b = num*currMin;
        currMax = max(a, max(b, num));
        currMin = min(a, min(b, num));
        res = max(currMax, res);
    }
    
    return res;
}