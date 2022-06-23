#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* dfs(Node* node, unordered_map<Node*, Node*> &mp) {
    if (!node) return NULL;
    
    // If node not cloned in map, then clone it, store it in map and 
    // store its neighbors recursively
    if (mp.find(node) == mp.end()) {
        mp[node] = new Node(node->val);
        
        for (auto it : node->neighbors) {
            mp[node]->neighbors.push_back(dfs(it, mp));
        }
    }
    
    // If a node is cloned, it will return as a neighbor
    return mp[node];
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}