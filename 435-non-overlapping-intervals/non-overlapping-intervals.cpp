class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // For Interval based question : 
        // Sort based on START TIME or END TIME 

        sort( intervals.begin() , intervals.end() )  ;

        int n = intervals.size() ; 
        int count = 0 ; 
        int i = 0 ;
        int j = 1 ; 

        while( j < n ){

            vector<int> curr = intervals[i] ; 
            vector<int> next = intervals[j] ; 

            int cs = curr[0] ;  // current start 
            int ce = curr[1] ;  // current end 

            int ns = next[0] ;  // next start 
            int ne = next[1] ;  // next end 

            if( ce <= ns ){ // Over lapping 
                i = j ; 
                j++ ; 
            }
            else if( ce <= ne ){
                j++ ; 
                count ++ ; 
            }

            else if( ce > ne ){ // Overlapping 
                i = j ; 
                j++ ;
                count ++ ; 
            }


        }

        return count ; 

    }
};