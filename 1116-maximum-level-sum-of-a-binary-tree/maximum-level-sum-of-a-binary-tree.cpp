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
    map<int,int> mp ;

    void DFS (TreeNode* root , int level ){

        if( root == NULL ) return ; 

        mp[level] += root->val ; 

        DFS( root->left  , level + 1 ) ; 

        DFS( root->right , level + 1 ) ; 

    } 

    int maxLevelSum(TreeNode* root) {
        
        // DFS Approach 
        mp.clear() ; 

        DFS( root , 1 ) ; 

        int maxsum = INT_MIN ; 

        int ans = 0 ; 

        for( auto &it : mp ){ // MAP : { level , sum }

            int level = it.first ; 
            int sum = it.second ; 

            if( sum > maxsum ){
                maxsum = sum ; 
                ans = level ; 
            }

        }

        return ans ; 
    }
};