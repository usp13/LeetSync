class Solution {
public:

    int modd = 1e9 + 7 ;
    int dp[201][201][201] ; 
    // DP: Recursion + Memoisation 
    int solve( vector<int>& nums, int i , int first , int second ){

        if( i == nums.size()) {

            bool bothnonempty = ( first != 0 && second != 0 ) ; 
            bool gcdmatch = ( first == second ) ;

            if( bothnonempty && gcdmatch ) return 1 ;
            else return 0  ;
        }

        if( dp[i][first][second] != -1 ){
            return dp[i][first][second] ; 
        }

        int skip = solve( nums , i+1 , first , second ) ; 

        int take1 = solve( nums , i+1 , __gcd(first,nums[i]) , second ) ; 

        int take2 = solve( nums , i+1 ,first ,  __gcd(second,nums[i]) ) ; 


        return  dp[i][first][second] = ( 0LL + skip + take1 + take2 ) % modd  ; 

    }

    int subsequencePairCount(vector<int>& nums) {

        memset( dp , -1 , sizeof(dp) ) ; 

        return solve( nums , 0 , 0 ,0 ) ;
        
    }
};