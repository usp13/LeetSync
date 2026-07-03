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
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* curr = root ;

        while( curr!= NULL ){
            if(curr-> val == val){
                return curr ; // value found
            }

            else if(curr-> val < val){ //Search right side 
                curr = curr->right ;
            }

            else { // Search left side 
                curr = curr-> left ;
            }
        }

        return NULL ; //if not present
        
    }
};