class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        // we will add the restriction for the building number one and last (if not present)
        
        // We will update the impossible heights , and update the restrictions with achievable height 
        
        // For a peak b/w two buildings with height H1 and H2 apart by distance 'd' , the peak will be : 

        // Peak = [ H1 + H2 + d ] / 2 


        restrictions.push_back( { 1 , 0 } ) ;

        sort( restrictions.begin() , restrictions.end() ) ;


        if( restrictions.back()[0] != n ){
            restrictions.push_back( { n , n-1 } ) ; // Pushing the restriction the last building , if it's not given already
        }

        int m = restrictions.size() ; 

        //updating heights from left to right 

        for( int i = 1 ; i < m ; i++ ) {

            int dist = restrictions[i][0] - restrictions[i-1][0] ; 

            restrictions[i][1] = min(  restrictions[i][1] ,  restrictions[i-1][1] + dist ) ;

        }

        // Updating heights from right to left 
        for( int i = m - 2 ; i >= 0 ; i-- ){

            int dist = restrictions[i+1][0] - restrictions[i][0] ; 

            restrictions[i][1] = min(  restrictions[i][1] ,  restrictions[i+1][1] + dist ) ;

        }

        long long ans = 0 ; 

        for( int i = 1 ; i < m ; i++ ){

            long long d1 = restrictions[i-1][0] ; 
            long long h1 = restrictions[i-1][1] ; 


            long long d2 = restrictions[i][0] ; 
            long long h2 = restrictions[i][1] ; 

            long long distance = abs( d2 - d1 ) ; 

            long long peak = ( h1 + h2 + distance ) / 2 ;

            ans = max( ans , peak ) ;  

        }

        return (int) ans ;

    }
};