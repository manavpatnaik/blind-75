#include <bits/stdc++.h>
using namespace std;

// pdt - product of all elements, ans[i] = pdt/nums[i]
// Handle 0's separately using conditions
vector<int> productExceptSelf(vector<int>& nums) {
    long long pdt = 1;
    int n = nums.size();
    unordered_set<int> zeroes;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0)
            pdt *= nums[i];
        else
            zeroes.insert(i);
    }
    
    vector<int> res(n, 0);
    if (zeroes.size() > 1)
        return res;

    for (int i = 0; i < n; i++) {
        if (zeroes.size() > 0) {
            if (zeroes.count(i) > 0)
                res[i] = pdt;
            else
                res[i] = 0;
        } else res[i] = (pdt/nums[i]);
    }
    
    return res;
}