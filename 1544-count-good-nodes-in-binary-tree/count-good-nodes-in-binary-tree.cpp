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
    void check(TreeNode* root , int maxi , int& count ){

        if( root == NULL ){
            return ;
        }
    
        if( root->val >= maxi ) count ++ ;

        check( root->left , max( maxi , root->val ) , count ) ;

        check( root->right , max( maxi , root->val ) , count ) ; 

    }

    int goodNodes(TreeNode* root) {
        
        int count1 = 0 ;
        int count2 = 0 ;

        check( root->left , root->val , count1 ) ; 

        check( root->right , root->val , count2 ) ; 

        return count1 + count2 + 1 ; 


    }
};