#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int water = 0, maxWater = 0;
    int l = 0, r = height.size()-1;
    while (l < r) {
        water = min(height[l], height[r])*(r-l);
        maxWater = max(water, maxWater);
        if (height[l] < height[r]) l++;
        else r--;
    }
    return maxWater;
}