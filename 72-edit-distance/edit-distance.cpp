class Solution {
public:

    int n , m ; 
    int dp[501][501] ; 

    //DP : Recursion + Memoisation
    int solve( string s1 , string s2 , int i , int j  ){

        if( i == m ){
            return n - j ; // insert in s1 
        }
        else if( j == n ){
            return m - i ; // delete from s1 
        }
        
        if( dp[i][j] != -1 ){
            return dp[i][j] ; 
        }
        if( s1[i] == s2[j] ){
            return solve( s1 , s2 , i+1 , j+1 ) ; 
        }
        else  {

            int insertchar = 1 + solve( s1 , s2 , i , j+1 ) ; 
            int deletechar = 1 + solve( s1 , s2 , i + 1 , j ) ;
            int replacechar = 1 + solve( s1 , s2 , i+1 , j+1 ) ; 

            return dp[i][j] = min( { insertchar , deletechar , replacechar }) ;

        }
        
        return -1 ; 

    }

    int minDistance(string s1, string s2) {

        m = s1.length() ;

        n = s2.length() ; 

        memset( dp , -1 , sizeof(dp))  ;

        return solve( s1 , s2 , 0 , 0  ) ;

        
    }
};