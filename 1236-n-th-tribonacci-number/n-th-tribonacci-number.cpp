class Solution {
public:

    int dp[40] ; 

    int solve( int n ){
        

        if( n == 0 ) return 0 ; 
        if( n == 1 || n == 2 ) return 1 ; 

        if( dp[n] != -1 ){
            return dp[n] ; 
        }

        int f1 = solve(n-1) ; 
        int f2 = solve(n-2) ; 
        int f3 = solve(n-3) ; 

        return dp[n] = ( f1 + f2 + f3 ) ; 

    }

    int tribonacci(int n) {

        memset( dp , -1 , sizeof(dp)) ; 

        return solve(n) ; 
        
    }
};