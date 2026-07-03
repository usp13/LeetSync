class Solution {
public:
    int numTilings(int n) {

        vector<long long> dp(n + 1 );
        if( n == 1 )
        return 1 ;
        if( n == 2 )
        return 2 ;
        if( n == 3 )
        return 5 ;

        dp[0] = 1 ;
        dp[1] = 2 ;
        dp[2] = 5 ;

        long long modd = 1e9 + 7 ;

        for( int i = 3 ; i < n ; i++){
            dp[i] = ((2*dp[i-1])%modd  + (dp[i-3]%modd))%modd   ;
        }

        return dp[n-1] ;

    }
};