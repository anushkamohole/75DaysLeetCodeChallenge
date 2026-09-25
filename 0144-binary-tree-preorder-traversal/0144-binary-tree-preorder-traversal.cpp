/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderHelper(TreeNode* root, vector<int>& vec){
        if (root == nullptr) {
            return;
        }
        vec.push_back(root->val);  
        preorderHelper(root->left, vec);             
        preorderHelper(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec; 
        preorderHelper(root, vec); 
        return vec;
    }
};