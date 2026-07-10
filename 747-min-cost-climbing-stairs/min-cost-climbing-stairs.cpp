class Solution {
public:

    int n ;
    int dp[1001] ; 

    // DP : Recursion + Memoization
    int solve( int i , vector<int>& cost ){

        if( i >= n ) return 0  ; 

        if( dp[i] != -1 ){
            return dp[i] ;
        }

        int a = cost[i] + solve(i+1 , cost ) ; // One jump
        int b = cost[i] + solve(i+2 , cost ) ; // Two jumps

        return dp[i] =  min(a,b) ;

    }
    int minCostClimbingStairs(vector<int>& cost) {

        n = cost.size() ;

        memset( dp , -1 , sizeof(dp) ) ;

        return min( solve( 0 , cost ) , solve( 1 , cost ) ) ; 
        
    }
};