class Solution {
public:

    int m , n ; 

    vector<vector<int>> directions{ {1,0} , {-1,0} , {0,1} , {0,-1} } ; // directions

    bool find( vector<vector<char>>& board, int i , int j , int idx, string& word ){

        if( idx == word.length() ){
            return true ; 
        }

        if( i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$'){
            return false ; 
        }

        if( board[i][j] != word[idx] ){
            return false ; 
        }

        char temp = board[i][j] ; // stored as temp 
        board[i][j] = '$' ; // markded as visited

        // BACKTRACKING
        for( auto &dir : directions ){

            int i1 = i + dir[0] ; // new i 
            int j1 = j + dir[1] ; // new j

            if( find( board , i1 , j1 , idx + 1 , word )){
                return true ; 
            }

        }

        board[i][j] = temp ; // stored back the temp value 

        return false ; // Not found , return false 
    }

    bool exist(vector<vector<char>>& board, string word) {
        

         m = board.size() ;  // rows
         n = board[0].size() ; // cols
        
        for( int i =  0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){

                if( board[i][j] == word[0] && find( board , i , j, 0 , word ) ){
                    return true ; 
                } 
            }
        }

        return false  ; 
    }
};