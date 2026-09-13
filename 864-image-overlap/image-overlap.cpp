class Solution {
public:

    int solve( vector<vector<int>>& A, vector<vector<int>>& B , int r , int c  ){

        int n = A.size() ; 

        int count = 0  ;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){

                int bi = i + r ; 
                int bj = j + c ; 

                if( bi < 0 || bi >= n || bj < 0 || bj >= n ){
                    continue ; 
                }

                if( A[i][j] == 1 && B[bi][bj] == 1 ){
                    count ++ ;
                }
            }
        }

        return count ; 
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B ) {

        int n = A.size() ; 

        int maxoverlap = 0 ; 

        for( int r = -n+1 ; r < n ; r ++ ){ // rowoff
            for( int c = -n+1 ; c < n ; c++ ){ // coloff

                int count = solve( A , B , r , c ) ;

                maxoverlap = max( maxoverlap , count )  ; 
            }
        }

        return maxoverlap ; 
        
    }
};