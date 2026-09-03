class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size() ; 

        vector<int> nums2 ; 
        nums2 = nums1 ; 

        int mini = INT_MAX ;
        bool odd = false ; 

        for( int i : nums2){

            if( i < mini ){
                mini = i ; // make minimum
            }

            if( i & 1 ){ // odd
                odd = true ;
            }
        }

        bool ans = ( mini & 1) || (!odd) ; 

        return ans ; 
        
    }
};