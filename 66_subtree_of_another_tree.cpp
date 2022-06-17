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

bool sameTree(TreeNode* a, TreeNode* b) {
    queue<TreeNode*> q;
    q.push(a);
    q.push(b);
    while (!q.empty()) {
        TreeNode* node1 = q.front(); q.pop();
        TreeNode* node2 = q.front(); q.pop();
        
        if (!node1 && !node2) continue;
        if (!node1 ^ !node2) return false;
        if (node1->val != node2->val) return false;
        
        q.push(node1->left);
        q.push(node2->left);
        q.push(node1->right);
        q.push(node2->right);
    }
    return true;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->val == subRoot->val) {
            if (sameTree(node, subRoot)) return true;
        }
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return false;
}