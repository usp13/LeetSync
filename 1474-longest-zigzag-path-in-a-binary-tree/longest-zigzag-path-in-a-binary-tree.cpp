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
    int maxpath = 0 ; 

    void solve( TreeNode* root , int steps , bool goleft ){

        if( root == NULL ) return ; 

        maxpath = max( maxpath , steps ) ; 

        if( goleft == true ){

            solve( root->left , steps+1 , false ) ; // went left , so next time goleft is false to make it a zigzag

            solve( root->right , 1 , true  ) ; 

        }
        else {
            
            solve( root->right , steps+1 , true ) ; // went right , so goleft == true for zigzag 

            solve( root->left , 1 , false ) ; 
        }
    }
    
    int longestZigZag(TreeNode* root) {

        solve( root , 0 , true ) ; 
        solve( root , 0 , false ) ; 

        return maxpath ; 

        
    }
};