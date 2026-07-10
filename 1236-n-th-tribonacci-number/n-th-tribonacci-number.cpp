class Solution {
public:

    // int dp[40] ; 
    // DYnamic Programming : Recursion + Memoization
    // int solve( int n ){
        

    //     if( n == 0 ) return 0 ; 
    //     if( n == 1 || n == 2 ) return 1 ; 

    //     if( dp[n] != -1 ){
    //         return dp[n] ; 
    //     }

    //     int f1 = solve(n-1) ; 
    //     int f2 = solve(n-2) ; 
    //     int f3 = solve(n-3) ; 

    //     return dp[n] = ( f1 + f2 + f3 ) ; 

    // }

    int tribonacci(int n) {

        // memset( dp , -1 , sizeof(dp)) ; 

        // return solve(n) ; 

        if( n == 0 ){
            return 0 ;
        }
        if( n == 1 || n == 2 ){
            return 1 ;
        }
        // Constant Space ! 
        int a = 0 ; 
        int b = 1 ; 
        int c = 1 ;
        int d = a + b + c ;

        for( int i = 3 ; i <= n ; i++ ){

            d = a + b + c ; 
            a = b ; 
            b = c ; 
            c = d ;
            
        }
        
        return d ; 

    }
};