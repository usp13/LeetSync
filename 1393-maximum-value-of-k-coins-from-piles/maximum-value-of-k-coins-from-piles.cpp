class Solution {
public:

    int n ;
    int dp[1001][2001] ; 

    // DP : RECURSION + MEMOIZATION 

    int solve( int i , vector<vector<int>>& piles, int k ){


        // BASE CASE
        if( i >= n  ){
            return 0 ; 
        }

        if( dp[i][k] != -1 ){
            return dp[i][k] ;
        }

        int sum = 0 ; 

        int nottaken =  solve( i + 1 , piles , k ) ; 

        int taken = 0 ; 

        for( int j = 0 ; j < min( (int)piles[i].size() , k ) ; j++ ){

            sum += piles[i][j] ; 

            taken = max( taken , sum + solve(i+1 , piles , k - (j+1) )) ; 
        }


        return dp[i][k]  = max( taken , nottaken ) ; 

    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        n = piles.size() ; 

        memset( dp , -1 , sizeof(dp)) ;

        int ans = solve( 0 , piles , k ) ; 

        return ans ; 
    }
};