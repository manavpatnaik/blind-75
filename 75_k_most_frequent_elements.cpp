#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    map<int, int> table;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int num : nums) table[num]++;
    
    for (auto it : table) pq.push(it);
    
    for (int i = 0; i < k; i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    
    return res;
}