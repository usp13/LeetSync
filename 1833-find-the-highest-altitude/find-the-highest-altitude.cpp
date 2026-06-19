class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int maxh = 0 ;
        int curr = 0 ;

        for( int i = 0 ; i < gain.size() ; i++ ){
            
            curr += gain[i] ;
            
            maxh = max( maxh , curr ) ;

        }

        return maxh ;
        
    }
};