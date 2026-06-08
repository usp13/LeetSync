class Solution {
public:

    // DP - Dynamic programming Approach

    int dp[501] ; 

    int solve( int i , vector<int> &arr , int k ){

        int n = arr.size() ; 

        if( i >= n ) {
            return 0 ; 
        }

        if( dp[i] != -1 ){
            return dp[i] ; 
        }

        int ans = 0 ;
        int currmax = -1 ; 

        for( int j = i ; j < n && j-i+1 <= k ; j++ ){

            currmax = max( currmax , arr[j]) ; 

            ans = max( ans , (j-i+1)*currmax + solve( j+1,  arr , k  ) ) ; 

        }
        return dp[i] = ans ; 
         
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size()  ;

        memset( dp , -1 , sizeof(dp) ) ; 

        return solve( 0 , arr , k ) ; 
        
    }
};