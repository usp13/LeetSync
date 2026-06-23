class Solution {
public:
    int MOD = 1e9 + 7 ;
    int zigZagArrays(int n, int l, int r) {

        //Shifting the range from (l,r) -> (0,r-l+1)
        //range [l, r] -> range[0, r-l+1]
        int m = ( r - l + 1 ) ; 

        vector<vector<int>> up( n+1 , vector<int>(m,0)) ;
        vector<vector<int>> down( n+1 , vector<int>(m,0)) ;

        for( int x = 0 ; x < m ; x++ ){
            for( int y = 0 ; y < m ; y++ ){

                if( x == y ) continue ;

                if( x < y ){

                    up[2][y] = ( up[2][y] + 1 ) % MOD ; 

                }
                else {

                    down[2][y] = ( down[2][y] + 1 ) % MOD ;  

                }
            }
        }

        for( int i = 3 ; i <= n ; i++ ){ 

            //PREFIX ARRAY
            vector<int> prefup( m+1 , 0 ) ;
            vector<int> prefdown( m+1 , 0 ) ;

            for( int v= 0 ; v < m ; v++ ){ // Building prefix array 

                prefup[v+1] = ( prefup[v] + up[i-1][v] ) % MOD ;
                prefdown[v+1] = ( prefdown[v] + down[i-1][v] ) % MOD ;

            }

            for( int y = 0 ; y < m ; y++ ){
                
                //up[i][y] = sum of down[i-1][x] for x < y ; 
                up[i][y] = prefdown[y] ; 

                //down[i][y] = sum of up[i-1][x] for x > y ; 
                down[i][y] = ( (prefup[m] - prefup[y+1])%MOD + MOD ) %MOD ;
            }


        }

        long long ans = 0 ;

        if( n == 1 ){
            ans = m ; 
        }
        // Sum all valid arrays of length n
        else { 
            for( int i = 0 ; i < m ; i++ ){

                ans = (ans + up[n][i] + down[n][i] )%MOD ;

            }
        }

        return ans ; 

        
    }
};