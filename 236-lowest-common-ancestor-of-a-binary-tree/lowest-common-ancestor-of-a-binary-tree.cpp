/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if ( root == NULL){
            return NULL ; // base case defining
        }

        if ( root == p || root == q){ // OR 
            return root ; // if leafnode is p,q, return root !
        }

        TreeNode* left  = lowestCommonAncestor(root-> left, p, q);
        TreeNode* right = lowestCommonAncestor(root-> right, p, q);

        if ( left != NULL && right != NULL){ // AND
            return root ; // if left and right of the root are found , thats the LOWEST COMMOM ANCESTOR ,  return the root !!!
        }

        return (left != NULL ? left : right) ;
                
    }
};