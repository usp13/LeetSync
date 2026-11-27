class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        map<int,int> freq ;

        for( auto &v : items ){

            for( int i = 1 ; i <= sqrt(v[0]) ; i++){

                if( v[0] % i ) continue ; 

                freq[i] ++ ;

                if( i != ( v[0] / i)) freq[v[0]/i] ++ ;
            }

        }

        vector<int> ans ( budget + 1 , 0 ) ;

        for( auto &v : items ){

            for( int i = budget ; i >= v[1] ; i-- ){

                ans[i] = max( ans[i] , ans[i - v[1]] + freq[v[0]] ) ;
            
            }


            for( int i = v[1] ; i <= budget ; i++ ){
                ans[i] = max( ans[i] , ans[i - v[1]] + 1 ) ;
            }
        }

        return ans[budget] ;
       
        
    }
};