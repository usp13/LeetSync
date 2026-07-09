class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size() ; 

        // SLIDING WINDOW of size "K"

        int sum = 0 ; 

        for( int i = 0 ; i < k ; i++ ){
            sum += nums[i] ; // sum of first k  
        }

        int maxsum = sum ; 

        int l = 0 ; 
        int r = k ; // Window of Size K 

        while( r < n ){

            sum -= nums[l] ; // remove the prev
            l++ ; 
            
            sum += nums[r] ; // Add the next element in window
            r++ ; 

            maxsum = max( maxsum , sum ) ; 

        }

        return (double) maxsum / k ; // return MAXIMUM AVG
        
    }
};