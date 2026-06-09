class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size() ; 

        int maxi = nums[0] ;
        int mini = nums[0] ; 

        for( int i = 0 ; i < n ; i++ ){

            if( nums[i] > maxi ){
                maxi = nums[i] ;
            }

            
            if( nums[i] < mini ){
                mini = nums[i] ;
            }
        }

        long long best = (long) ( maxi - mini ) ; 

        return ( best * k ) ; 
        
    }
};