class Solution {
public:

    int n ; 
    int m ; 
    int apples[55][55] ; // Only for Recursion
    int modd = 1e9 + 7 ; 

    int dp[55][55][15] ; // dp[i][j][k] 

    //1 <= rows, cols <= 50
    // 1 <= k <= 10


    // DP = Recursion + Memoizaton
    int solve(int i , int j , int k  ){


        // Base Case 
        if( apples[i][j] < k ){
            return 0 ; 
        }

 

        if( k == 1 ){ // One slize = whole Pizza

            if( apples[i][j] >= 1 ){ // One way
                return 1 ; 
            }
            return 0 ; // No ways
        }


        if( dp[i][j][k] != -1 ){
            return dp[i][j][k] ; 
        }


        int ans = 0 ; 

        // HORIZONTAL CUT 
        for( int h = i + 1 ; h < m ; h++ ){

            int lower = apples[h][j] ; 
            int upper = apples[i][j]  - lower  ; 

            if( upper >= 1 && lower >= k-1 ){

                ans = ( ans %modd +  solve( h , j , k-1 )%modd ) %modd ; // vertical cut deducted one slice ( k-1 )
            } 

        }

         // VERTICAL CUT 
        for( int v = j + 1 ; v < n ; v++ ){


            int right = apples[i][v] ; 

            int left = apples[i][j] - right ; 

            if( left >= 1 && right >= k-1 ){

                ans = (ans %modd +  solve( i , v , k-1 )%modd) %modd ; // vertical cut deducted one slice ( k-1 )
            } 

        }


        return dp[i][j][k] = ans ; 

    }

    int ways(vector<string>& pizza, int k) {

        m = pizza.size()  ; 
        n = pizza[0].size()  ; 


        memset( apples , 0 , sizeof( apples )) ; 

        memset( dp , -1 , sizeof(dp) ) ; 

        for( int i = m - 1 ; i >= 0 ; i-- ){

            for( int j = n-1 ; j >= 0 ; j-- ){

                apples[i][j] = apples[i][j+1] ; 

                for( int l = i ; l < m ; l++ ){

                    if( pizza[l][j] == 'A' ){
                        apples[i][j] += 1 ; 
                    }
                }
            }
        }


        return solve( 0 , 0 , k ) ; 
        
    }
};