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
    TreeNode* nextright = NULL ; 

    void flatten(TreeNode* root) {

        if( root == NULL ){
            return ; 
        }
        
        // Call for Right Subtree
        flatten( root -> right ) ; 


        // Call for Left Subtree
        flatten( root -> left ) ;

        // Update all the values 
        root->left = NULL ; 

        root->right = nextright ;

        nextright = root ;  



    }
};