#include <bits/stdc++.h>
using namespace std;

// Use a hashmap to to store elements and indices
// and search for a match against it
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> table;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (table.find(target - nums[i]) != table.end()) {
            table[nums[i]] = i;
        } else {
            res.push_back(table[target-nums[i]]);
            res.push_back(i);
            break;
        }
    }
    return res;
}

int main() {}