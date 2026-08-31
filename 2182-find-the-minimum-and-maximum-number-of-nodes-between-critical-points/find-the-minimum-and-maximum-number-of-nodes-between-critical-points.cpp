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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return ans;

        ListNode* start = head;
        ListNode* curr = head->next;

        int idx=1;
        int first=-1;
        int last=-1;

        int mindis = INT_MAX;
        int maxdis = -1;

        while(curr->next!=nullptr){

            ListNode* end = curr->next;
            bool check = (curr->val > start->val && curr->val > end->val) || (curr->val < start->val && curr->val < end->val);

            if(check){

                if(first==-1){
                    first = idx;
                }else{
                    mindis = min (mindis, idx - last);

                    maxdis = idx - first;
                }
                last = idx;
            }
            start= curr;
            curr = end;
            idx++;
        }

        if(first == last) return {-1, -1};

        return {mindis, maxdis};

    }
};