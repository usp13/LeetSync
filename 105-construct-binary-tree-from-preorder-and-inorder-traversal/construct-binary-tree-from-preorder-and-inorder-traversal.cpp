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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int start , int end , int &idx  ){

        if( start > end ){
            return NULL ; 
        }

        // ROOT VALUE SET TO idx pointer
        int rootval = preorder[idx] ; 
        int i = start ; 

        for( i = start ; i <= end ; i++){

            if( inorder[i] == rootval ){
                break ; 
            }
        }
        idx ++ ; 

        TreeNode* root = new TreeNode( rootval ) ;

        root->left = solve(preorder , inorder , start , i - 1 , idx) ; // left = From start to i-1 
        root->right = solve(preorder , inorder , i + 1, end, idx) ; 
        // right = From i+1 to end

        return root ; 

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size() ; 
        // Iterate in Preorder to find the root , then confirm left child of the in Inorder

        int start  = 0 ;
        int end = n-1 ; 
        int idx = 0 ;

        return solve(preorder , inorder , start , end , idx) ; 

        
    }
};