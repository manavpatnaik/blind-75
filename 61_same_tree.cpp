#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    
    queue<TreeNode*> q1;
    q1.push(p);
    q1.push(q);
    
    while (!q1.empty()) {
        p = q1.front(); q1.pop();
        q = q1.front(); q1.pop();
        
        if (!p && !q) continue;
        if (!p ^ !q) return false;
        if (p->val != q->val) return false;
        
        q1.push(p->left);
        q1.push(q->left);
        q1.push(p->right);
        q1.push(q->right);
    }
    
    return true;
}