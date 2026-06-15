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

    int maxsum ;

    int solve( TreeNode* root) {

        if( root == NULL ){
            return 0 ; 
        }

        int l = solve( root->left ) ; // left side 
        int r = solve( root->right ) ; // right side 

        int bothpart = l + r + root->val ; // CASE 1

        int onepart = max( l , r ) + root->val ;// CASE 2

        int onlyroot = root->val ; // CASE 3

        maxsum = max({ maxsum ,bothpart , onepart , onlyroot }) ; 

        // Case 2 and 3 have a possibilty that better sum can be found
        
        return max( onepart , onlyroot ) ;

    }

    int maxPathSum(TreeNode* root) {

        // case 1 : left part + right part + root 
        // case 2 : Max(left part , right part ) + root 
        // case 3 : Only Root->value 

        maxsum = INT_MIN ;

        solve(root) ;

        return maxsum ; 

        
    }
};