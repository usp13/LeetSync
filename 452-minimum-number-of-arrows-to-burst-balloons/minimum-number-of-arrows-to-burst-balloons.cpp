class Solution {
public:


static bool comp(vector<int> &a , vector<int> &b ){
    
    if(a[1] < b[1]){
        return true ;
    }
    
    return false ;
}

    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();

        sort( points.begin(), points.end(), comp);

        int ans = 1 ;
        auto l = points[0] ;

        for( int i = 1 ; i < n ; i++){
            if(points[i][0] > l[1]){
                l = points[i];
                ans ++ ;
            }
        }

        return ans ;
        
    }
};