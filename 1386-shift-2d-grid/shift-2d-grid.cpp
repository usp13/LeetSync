class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size() ; // rows
        int n = grid[0].size() ; // cols

        int total = m * n ;  

        k %= total ; 

        vector<vector<int>> ans( m , vector<int>(n)) ;
        

        for( int i  = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){

                int old = (i * n) + j ; // old index

                int newidx = ( old + k ) % total ;  // new index ( after rotation)

                int newrow = newidx / n ; 
                int newcol = newidx % n ; 

                ans[newrow][newcol] = grid[i][j] ; 

            }
        }

        return ans ; 

        
    }
};