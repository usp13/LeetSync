class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size() ; 
        
        int flag = 1 ; 

        // sliding window 
    
        int ans = 0 ;
        int prev = 0 ; 
        int win = 0 ;

        for( int i = 0 ; i < n ; i++){

          // increase window length

            if( nums[i] == 0) {
                if(flag){
                    flag = 0 ; 
                    prev = i ;
                }

                else {
                    ans = max( ans, win ) ;
                    win = i - prev ;
                    prev =  i ; 
                    continue ;
                }
            }
         
            win ++ ;

        }

        ans = max( ans, win ) ;

        return ans - 1 ;   

    }
};