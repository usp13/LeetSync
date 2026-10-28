class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int r = grid.size() ; //row
        int c = grid[0].size() ; //col

        vector<vector<int>> grid2 = grid ;

        vector<vector<bool>> dp( c , vector<bool>( 1024 , false )) ; // 0 <= grid[i][j] <= 1023
        dp[0][grid2[0][0]] = true ;

        for( int i = 0 ; i < r ; i++){ // row loop
            for( int j  = 0 ; j < c ; j++){ // col loop

                if( i == 0 && j == 0 ){
                    continue ;
                }

                vector<bool> x ( 1024 , false ) ;

                int value = grid[i][j] ;

                for( int k = 0 ; k < 1024 ; k++){
                    if( ( i > 0 && dp[j][k] ) || ( j > 0 && dp[j-1][k])){
                        x[ k ^ value ] = true ; 
                    }
                }

                dp[j] = x ; 
                
                
            }
        }

        for( int i  = 0 ; i < 1024 ; i++){
            if( dp[c-1][i]) {
                return i ;
            }
        }

        return -1 ; 
        
    }
};