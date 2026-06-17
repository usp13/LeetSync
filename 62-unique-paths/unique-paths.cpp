class Solution {
public:

    // Dynamic Programming : Recursion + memoisation 
    
    int dp[101][101] ; 

    int countpaths( int i , int j , int m , int n  ){

        if( i < 0 || i >= m || j < 0 || j >= n ){
            return 0 ; 
        }

        if( i == m-1 && j == n-1 ){ // Reached the destination
            return 1 ;
        }

        if( dp[i][j] != -1 ){
            return dp[i][j] ; 
        }

        int right = countpaths( i , j + 1 , m , n ) ;
        int down = countpaths( i + 1 , j , m , n ) ;

        return dp[i][j] = ( right + down ) ; 

    }

    int uniquePaths(int m, int n) {

        // Robot can either go down and right , or right and down 
        memset( dp , -1 , sizeof(dp) ) ; 

        return countpaths( 0 , 0 , m , n ) ;  
        
    }
};