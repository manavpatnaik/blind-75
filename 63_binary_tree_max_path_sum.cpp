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

int maxSum = INT_MIN;

int dfs(TreeNode *root) {
    if (!root) return 0;
    
    int leftMax = max(dfs(root->left), 0);
    int rightMax = max(dfs(root->right), 0);
    
    // Storing the maxSum at every path computation
    // This will take care of the max in case there are no max
    // Above in the tree
    maxSum = max(maxSum, root->val+leftMax+rightMax);
    
    // While returning we dont return both left and right Max
    // Only return the max of either left or right
    // Else root may get overlapped in the path
    return max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return maxSum;
}