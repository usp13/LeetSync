class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size() ; // row
        int m = grid[0].size() ; // col

        int count = 0 ; 

        // BRUTE FORCE - > O(n^3)
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++ ){

                bool equal = true ; 

                for( int r = 0 ; r < n ; r++ ){

                    if( grid[i][r] != grid[r][j] ){
                        equal = false ; 
                        break ;
                    }

                }

                
                 if( equal ){
                    count ++ ;
                }
            }
        }

        return count ; 


        
    }
};