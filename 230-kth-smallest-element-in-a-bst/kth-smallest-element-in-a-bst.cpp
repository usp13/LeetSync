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
    int prevorder = 0;

    int kthSmallest(TreeNode* root, int k) {

        if (root == NULL) {
            return -1;
        }

        // Traverse left subtree
        if (root->left != NULL) {

            int leftans = kthSmallest(root->left, k);

            if (leftans != -1) {
                return leftans;
            }
        }

        // Current node is the kth visited node
        if (prevorder + 1 == k) {
            return root->val;
        }

        prevorder++;

        // Traverse right subtree
        if (root->right != NULL) {

            int rightans = kthSmallest(root->right, k);

            if (rightans != -1) {
                return rightans;
            }
        }

        return -1;
    }
};