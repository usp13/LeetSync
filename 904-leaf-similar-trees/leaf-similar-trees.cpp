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

    void inorder(TreeNode* root, vector<int> &leaf) {

        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
            return;
        }

        inorder(root->left, leaf);
        inorder(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        // Traverse both trees and collect all leaf nodes

        vector<int> leaf1;
        vector<int> leaf2;

        inorder(root1, leaf1);
        inorder(root2, leaf2);

        return leaf1 == leaf2;
    }
};