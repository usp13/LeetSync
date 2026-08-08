class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //KADANE's ALGO 

        int maxsum = nums[0]  ; // initialise with first value
        int currsum = 0 ; 


        for( int i = 0; i < nums.size() ; i++ ){

            currsum += nums[i] ;

            maxsum = max( maxsum , currsum ) ;

            if( currsum < 0 ){ // if it becomes negetive
                currsum = 0 ; // reinitialise the currsum to 0 
            }
        }

        return maxsum ; 
        
    }
};