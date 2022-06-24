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

class Codec {
public:

    void preorder(TreeNode *root, string &res) {
        if (!root) {
            res += "N,";
            return;
        }
        res += to_string(root->val);
        res += ",";
        preorder(root->left, res);
        preorder(root->right, res);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorder(root, res);
        return res;
    }

    vector<string> splitString(string str, char delim) {
        vector<string> res;
        string temp;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == delim && temp != "") {
                res.push_back(temp);
                temp = "";
            } else {
                temp += str[i];
            }
        }
        return res;
    }
    
    int i;
    TreeNode* buildTree(vector<string> &nodes) {
        if (nodes[i] == "N" || i >= nodes.size()) return NULL;
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = buildTree(nodes);
        i++;
        root->right = buildTree(nodes);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;
        
        vector<string> nodes = splitString(data, ',');
        
        i = 0;
        return buildTree(nodes);        
    }
};