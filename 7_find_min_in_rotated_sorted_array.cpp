#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int minimum = nums[0];
    int low = 0, high = nums.size()-1;
    int mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        minimum = min(minimum, nums[mid]);
        if (nums[mid] < nums[high]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return minimum;
}