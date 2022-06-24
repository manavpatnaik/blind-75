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

unordered_map<int, int> m;
int currIndex;

TreeNode* getTree(vector<int> &preorder, vector<int> &inorder, int start, int end) {
    if (start > end) return NULL;
    
    // The first index of preorder is the root
    int curr = preorder[currIndex++];
    TreeNode* root = new TreeNode(curr);
    
    // Return if there is only 1 node currently
    if (start == end) return root;
    
    int mid = m[curr];
    
    root->left = getTree(preorder, inorder, start, mid-1);
    root->right = getTree(preorder, inorder, mid+1, end);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {    
    // Store indices of nodes, so that we wont have to 
    // search for them recursively later in inorder to find mid
    for (int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }
    currIndex = 0;
    return getTree(preorder, inorder, 0, preorder.size()-1);
}