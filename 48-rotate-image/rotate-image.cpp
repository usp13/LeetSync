class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // rotate = transpose + reverse 

        // transpose = swap matrix[i][j] with matrix [j][i]


        int m = matrix.size() ; //rows

        int n = matrix[0].size() ; //cols

        //square matrix has rows == cols

        //TRANSPOSE
        for( int i = 0 ; i < m ; i++ ){
            for( int j = i ; j < n ; j++ ){
                swap(matrix[i][j], matrix[j][i]) ;
            }
        }

        //REVERSE
        for( int i = 0 ; i < m ; i++ ){
            reverse(matrix[i].begin(), matrix[i].end()) ;
        }


        //return matrix ;

    }
};