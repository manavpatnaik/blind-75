#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, map<int, set<int>> &preReqMap, set<int> &visited) {
    if (preReqMap[node].size() == 0) return true;
    
    for (int adj : preReqMap[node]) {
        if (visited.count(adj) > 0) return false;
        visited.insert(adj);
        if (!dfs(adj, preReqMap, visited)) return false;
        visited.erase(adj);
    }
    preReqMap[node].clear();
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, set<int>> preReqMap;
    set<int> visited;
    
    for (auto p : prerequisites) {
        preReqMap[p[0]].insert(p[1]);
    }
    
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, preReqMap, visited)) return false;
    }
    return true;
}