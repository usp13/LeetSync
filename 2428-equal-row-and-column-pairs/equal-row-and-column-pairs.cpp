class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size() ; // row
        int m = grid[0].size() ; // col
        int count = 0 ; 
        
        // Using HASH MAP - > O(n^2)
      
        map< vector<int> , int> mp ; 

        // Adding all the rows in MAP
        for( int r = 0 ; r < n ; r++ ){
            mp[grid[r]] ++ ;
        }

        for( int c = 0 ; c < n ; c++ ){
           
            vector<int> v ; // temporary vector

            for( int r = 0 ; r < n ; r++ ){
                v.push_back( grid[r][c] ) ; // Pushing Vector in 
            }

            count += mp[v] ;  // If its present , it will be added to count

          
        }

        return count ; 

        
    }
};