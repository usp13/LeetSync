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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if ( head == NULL || head->next == NULL ){
            return NULL ;
        }

        // TWO POINTER 

        ListNode* prevslow = NULL ; // previous of  slow pointer
        ListNode* slow = head ; // Slow pointer 
        ListNode* fast = head ; // fast pointer 

        while( fast != NULL && fast->next != NULL ){

            prevslow = slow ;

            slow = slow ->next ; 

            fast = fast->next->next ; 

        }

        prevslow->next = slow->next ; 
        delete(slow) ;

        return head ; 





        
    }
};