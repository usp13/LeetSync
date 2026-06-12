class Solution {
public:

    int n ; // cols
    int m ; // rows 
    int perimeter ; 

    void DFS( vector<vector<int>>& grid , int i , int j  ){

        if( i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 ){
            perimeter ++ ;
            return ; 
        }

        if( grid[i][j] == -1 ){
            return ;
        }

        grid[i][j] = -1 ; // Marked unvisited 

        DFS( grid , i+1 , j )  ; 
        DFS( grid , i-1 , j )  ; 
        DFS( grid , i , j+1 )  ; 
        DFS( grid , i , j-1 )  ; 


    }

    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size() ; // rows
        n = grid[0].size() ; // cols

        perimeter = 0 ; 

        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++ ){

                if( grid[i][j] == 1 ){

                    DFS( grid , i , j ) ;
                    
                    
                }
            }
        }

        return perimeter ;
        
    }
};