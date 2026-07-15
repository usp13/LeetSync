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
    int maxLevelSum(TreeNode* root) {
        
        int maxi = INT_MIN ;
        int ans = 0 ; // Minimum level 


        // BFS approach : With QUEUE
        queue<TreeNode*> q ; 
        q.push( root ) ; 

        int currlevel = 1;  

        while( !q.empty() ){

            int n = q.size() ;

            int sum = 0  ;

            while( n -- ){// Traversing the current level

                TreeNode* temp = q.front() ;
                q.pop() ; 

                sum += temp->val ; // add the value 

                if( temp->left ){ // if left child
                    q.push(temp->left ) ; // push left child
                }

                if( temp->right ){ // if right child
                    q.push(temp->right ) ; // push right child
                }

            }

            if( sum > maxi ) {
                maxi = sum ;
                ans = currlevel ; 
            }

            currlevel ++ ; 
        }

        return ans ;

    }
};