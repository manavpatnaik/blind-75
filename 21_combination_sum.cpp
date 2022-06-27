#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &candidates, vector<vector<int>> &res, int i, int total,
            int target, vector<int> &curr) {
    if (target == total) {
        res.push_back(curr);
        return;
    }
    if (i >= candidates.size() || total > target) return;
    
    // Choose to include current candidate
    curr.push_back(candidates[i]);
    dfs(candidates, res, i, total+candidates[i], target, curr);
    // Or proceed with the next one
    // We pop to avoid duplication of the same combination
    curr.pop_back();
    dfs(candidates, res, i+1, total, target, curr);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(candidates, res, 0, 0, target, temp);
    return res;
}