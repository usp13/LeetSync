class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort( intervals.begin(), intervals.end()) ;

        int total = 1;
        int last =  0; 
        int n = intervals.size() ;

        int maxi = intervals[0][1];

        for( int i = 0 ; i < n ; i++){
           
            if(intervals[last][0] != intervals[i][0] && intervals[i][1] > maxi){
                maxi = intervals[i][1];
                last = i ;
                total ++ ;
            }

            else if( intervals[last][0] == intervals[i][0] && intervals[i][1] > maxi) {
                maxi = intervals[i][1];
                last = i ;

            }
        }

        return total ;
    }
};