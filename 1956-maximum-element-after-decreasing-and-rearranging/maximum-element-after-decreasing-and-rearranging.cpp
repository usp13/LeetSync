class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size() ;

        sort( arr.begin() , arr.end() ) ;

        int maxi = -1; // max element

        for( int i = 0 ; i < n ; i++ ){
            
            if( i == 0 ){

                arr[0] = 1 ; // Make first eleemnt 1 

            }

            else if( abs(arr[i] - arr[i-1]) > 1 ){

                arr[i] = arr[i-1] + 1 ; // Update with one more than prev

            }

            

            maxi = max( maxi , arr[i] ) ;

        } 

        return maxi ; 

    }
};