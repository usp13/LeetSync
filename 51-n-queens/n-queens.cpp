class Solution {
public:

    int N ;
    vector<vector<string>>  ans ; 

    bool isvalid( vector<string>& board , int row, int col ){

        // Filling from upwards, we should keep a track of all queens placed in the upwards , left and right direction

        // Upward Check 
        for( int i = row - 1 ; i >= 0 ; i-- ){
            if( board[i][col] == 'Q' ){
                return false ; 
            }
        }

        // FORLOOP with Two variables

        //Left Diagonal Check upwards 
        for( int i = row - 1, j = col -1  ; i >= 0 && j >= 0 ; i-- , j-- ){

            if( board[i][j] == 'Q' ){
                return false ; 
            }

        }

        //Right Diagonal Check upwards
        for( int i = row - 1, j = col + 1  ; i >= 0 && j < N ; i-- , j++ ){

            if( board[i][j] == 'Q' ){
                return false ; 
            }
            
        }

        return true ;

    }

    void solve( vector<string>& board , int row ){


        if( row == N ){
            ans.push_back( board ) ; 
        }

        for( int col = 0 ; col < N ; col ++ ){

            if( isvalid( board , row , col )){

                board[row][col] = 'Q' ; // Place the queen 

                solve( board , row + 1 ) ;

                board[row][col] = '.' ; // Place the empty space back 

            }
        }

    }

    // BACK TRACKING
    vector<vector<string>> solveNQueens(int n) {
        
        N = n ; 

        vector<string> board( n , string( n , '.')) ; 
        /*  .... 
            ....
            ....
            ....   */
        
        solve( board , 0 ) ; 

        return ans ; 
    }
};