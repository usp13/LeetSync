class Solution {
public:

    vector<vector<int>> dir { {-1,0} , {1,0} , {0,-1} , {0,1} } ;
    // Direction vector for left , right  , up , down

    int orangesRotting(vector<vector<int>>& grid) {

        //0 representing an empty cell,
        //1 representing a fresh orange, 
        //2 representing a rotten orange.

        int m = grid.size() ; // rows 
        int n = grid[0].size() ; // cols

        // Using Multi-Source BFS

        // All the rotten oranges will work simultaniously 
    
        queue<pair<int,int>> q ; // Store the coordinates of the cells
        int fresh = 0 ; // count of fresh oranges

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){

                if( grid[i][j] == 2 ){ // is rotten
                    q.push( {i,j} ) ; // push rotten                  
                }
                else if( grid[i][j] == 1 ){ // is fresh
                    fresh ++ ;
                }
            }
        }

        if( fresh == 0 ) return 0 ; // all are already rotten

        int minutes = 0 ; // time 

        while( ! q.empty() ){

            int size = q.size() ; 

            while( size -- ){

                pair<int,int> curr = q.front() ; 
                q.pop() ; 

                int i = curr.first ;
                int j = curr.second ;

                for( vector<int>& d : dir ){

                    int newi = i + d[0] ; 
                    int newj = j + d[1] ; 

                    if( newi >= 0 && newi < m && 
                        newj >= 0 && newj < n && 
                        grid[newi][newj] == 1 ) {

                            grid[newi][newj] = 2 ; // new rotten orange
                            q.push( {newi ,newj } ) ; // It will also be pushed in queue to rot others
                            fresh -- ; // fresh orange -- 
                    }

                }
                
            }

            minutes ++ ; 
        }

        if( fresh == 0 ){
            return minutes - 1 ; 
        }
        else {
            return -1 ; 
        }
        
    }
};