#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    
    if (n < 3) return res;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n-2; i++) {
        int a = nums[i];
        if (i > 0 && a == nums[i-1]) continue;
        
        int b = i+1, c = n-1;
        while (b < c) {
            int sum = a+nums[b]+nums[c];
            if (sum == 0) {
                res.push_back({a,nums[b],nums[c]});
                b++;
                while (b < n && nums[b] == nums[b-1]) b++;
            } else if (sum > 0) {
                c--;
            } else {
                b++;
                while (b < n && nums[b] == nums[b-1]) b++;
            }
        }
    }
    
    return res;
}

int main() {}