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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        // Base case: if our range is invalid, this subtree is empty
        if (left > right) {
            return NULL;
        }

        // 1. The current element in preorder is always the root of the current subtree
        int rootVal = preorder[preIdx];
        TreeNode* root = new TreeNode(rootVal);
        
        // Move to the next element in preorder for subsequent calls
        preIdx++;

        // 2. Find the index of this root value in the inorder array
        int inIdx = left;
        while (inIdx <= right && inorder[inIdx] != rootVal) {
            inIdx++;
        }

        // 3. Recursively build the left and right subtrees
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};