class Solution {
public:

    // 1 <= jobDifficulty.length <= 300
    //0 <= jobDifficulty[i] <= 1000
    //1 <= d <= 10

    int dp[301][11] ; 

    int solve(vector<int>& jobDifficulty , int n , int idx , int d ){

        // DP :  Recursion + Memoisation -> Top down Approach 

        //BASECASE  
        // When only one day is left , do all the remaining jobs and find the max 
        if( d == 1 ){

            int maxd = jobDifficulty[idx] ; 

            for( int i = idx ; i < n ; i++ ){
                maxd = max( maxd , jobDifficulty[i]) ; 
            }

            return maxd ; 
        }

        if( dp[idx][d] != -1 ){
            return dp[idx][d] ;
        }

        // Try out all the possibilities: 
        // Take {idx} job on day 1 , remaining in other days
        // Take {idx , idx + 1} job on day 1 , remaining in other days 
        // Take {idx , idx + 1, idx + 2 } job on day 1 , remaining in other days 
        // ... and so on 

        int maxd = jobDifficulty[idx] ;
        int final = INT_MAX ; 

        for( int i = idx ; i <= n - d ; i++ ){

            maxd = max( maxd , jobDifficulty[i] ) ; 

            int result = maxd + solve( jobDifficulty , n , i+1 , d-1 ) ; 

            final = min( final , result ) ; 
        }

        return dp[idx][d] = final  ; 

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size() ; 

        if( n < d ){ // no. of days is greater
            return -1 ;
        }

        memset( dp , -1 , sizeof(dp) ) ;

        return solve( jobDifficulty , n , 0 , d ) ; 
        
    }
};