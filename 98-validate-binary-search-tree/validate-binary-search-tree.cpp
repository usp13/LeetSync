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

    bool check(TreeNode* root , long long minValue, long long maxValue){

        if(root == NULL) return true ;

        if( (long long) root-> val < minValue ||(long long)root -> val > maxValue){
            return false ;
        }

        // (long long) is for converting int to long long

        // DFS
        bool left = check(root->left , minValue,  (long long)root->val -1) ; 

        bool right = check(root->right , (long long) root->val+1 , maxValue) ;

        bool ans  = ( left && right ) ;

        return ans ;


    }

    bool isValidBST(TreeNode* root) {

        bool ans = check( root, INT_MIN, INT_MAX ) ;

        return ans ; 
        
    }
};