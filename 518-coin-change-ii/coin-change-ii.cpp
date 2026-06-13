class Solution {
public:
    int n ; 
    int dp[301][5001] ; 
    
    //Constraints:
    //1 <= coins.length <= 300
    //1 <= coins[i] <= 5000
    
    int solve( int i , int amount , vector<int>& coins ){

        if( amount  == 0 ) return 1 ; 

        if( i == n ) return 0 ; 

        if( dp[i][amount] != -1 ) {
            return dp[i][amount] ;
        }

        if( amount < coins[i] ){
            return dp[i][amount] = solve( i+1 , amount , coins) ;
        }

        int take = solve( i , amount - coins[i] , coins ) ; // take the coin
        int nottake = solve( i + 1 , amount , coins ) ; // Not take the coin

        return dp[i][amount] = (take + nottake) ; 



    }
    int change(int amount, vector<int>& coins) {

        n = coins.size() ; 

        // DP : Using take or not take cases

        memset( dp , -1 , sizeof(dp)) ; 

        return solve( 0 , amount , coins ) ;
        
    }
};