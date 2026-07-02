class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size() ; 

        int count = 0 ; 
        int maxcount = 0 ; 
        int l = 0 ;  
        int zero = 0 ; //no of zeros encountered


        for(int  r = 0 ; r < n ; r++ ){

            if( nums[r] == 0 ){
                zero ++ ;
            }

            if( zero > k ){

                if( nums[l] == 0 ){
                    zero -- ;
                }

                l++ ;
            }

            //maxcount = max( maxcount , r - l + 1) ;
        }

        int ans = n - l ; // max len
    

        return ans ; 
        
    }
};