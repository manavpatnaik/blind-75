#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        
        int count = 0, currMax = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currMax = 0;
            if (s.count(nums[i]-1) == 0) {
                int curr = nums[i];
                while (s.count(curr) > 0) {
                    currMax++;
                    curr++;
                }
            }
            count = max(count, currMax);
        }
        
        return count;
    }

int main() {

}