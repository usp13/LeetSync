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
    int pairSum(ListNode* head) {

        vector<int> arr ; 

        while( head != NULL ){
            
            arr.push_back( head -> val ) ; // adding all the values of linked list to vector

            head = head ->next ; // head points to next pointer 
        }


        // TWO POINTERS 
        int l = 0  ;
        int r = arr.size() -  1;

        int ans = 0 ; 

        while( l < r ){

            ans = max( ans , arr[l] + arr[r] ) ; 

            l++ ; 
            r-- ;
        } 

        return ans ; 
        
    }
};