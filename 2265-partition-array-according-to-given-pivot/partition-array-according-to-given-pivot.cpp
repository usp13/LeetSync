class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size() ; 
        
        // TWO POINTERS
        int i = 0 ; //left
        int j = nums.size() - 1 ; //right

        vector<int> ans (n) ; 

        // POINTERS for ANSWER ARRAY 
        int ai = 0 ; 
        int aj = nums.size() - 1  ;

        while( i < n && j >= 0 ){ 

            if( nums[i] < pivot ){ // Filling from front
                ans[ai] = nums[i] ; 
                ai++ ;  
            }

            if( nums[j] > pivot ){ // filling from BACK
                ans[aj] = nums[j] ; 
                aj-- ;  
            }

            i++ ; 
            j-- ; 

        }

        // Fill the remaining spaces of ANSWER vector with "PIVOT" , because thats the only one left

        while( ai <= aj ){
            ans[ai] = pivot ;
            ai++ ;
        }

        return ans ; 

    }
};