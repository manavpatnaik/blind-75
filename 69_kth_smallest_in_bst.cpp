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

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        
        root = st.top();
        st.pop();
        k--;
        if (k==0) return root->val;
        
        root = root->right;
    }
    return -1;
}