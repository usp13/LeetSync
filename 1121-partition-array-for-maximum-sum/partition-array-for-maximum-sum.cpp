class Solution {
public:

    // DP : Memoise + Bottom Up 
 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size()  ;

        vector<int> dp( n+1 , 0) ;

        for( int size = 1 ; size <= n ; size++ ) {

            int currmax = -1 ;

            for( int j = 1 ; j <= k && size - j >= 0 ; j++ ){

                currmax = max( currmax , arr[size-j]) ; 
            
                dp[size] = max( dp[size] , (j*currmax) + dp[size - j] ) ;

            }
        }

       
        return dp[n] ;

        
        
    }
};