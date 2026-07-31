/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {

        // LINKED LIST's Middle Node : using three pointers : slow , fast and prev of slow


        if( head == NULL ){
            return NULL ; 
        }

        if( head->next == NULL ){
            return new TreeNode( head ->val) ; 
        }

        // 3 Pointers 

        ListNode* slow = head ;
        ListNode* slowprev = NULL ;
        ListNode* fast = head ;

        while( fast != NULL && (fast->next) != NULL ){

            // Increment all 3 pointers
            slowprev = slow ; 
            slow = slow->next ;
            fast = (fast->next) -> next ; 

        }


        TreeNode* root = new TreeNode( slow-> val) ; 

        slowprev->next = NULL ; 

        root->left = sortedListToBST( head ) ; 

        root->right = sortedListToBST( slow->next ) ; 

        return root  ; 

        
    }
};