class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> dist ;
        int n = points.size() ;

        for( int i = 0 ; i < n ; i++){
            dist.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1], points[i][0] , points[i][1] } ) ;
        }

        sort(dist.begin(), dist.end() ) ;


        vector<vector<int>> ans ;


        for( int i = 0 ; i < k ; i++){

            ans.push_back({dist[i][1], dist[i][2]}) ;
        }

        return ans ;

        
    }
};