class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int len = flowerbed.size() ; 

        if( n == 0 ){
            return true ; 
        }

        for( int i = 0 ; i < len ; i++ ){

            if( flowerbed[i] == 0 ){ // empty

                int leftempty = ( i == 0 ) || (flowerbed[i-1] == 0 ) ;

                int rightempty = ( i == len - 1  ) || (flowerbed[i+1] == 0 ) ;

                if( leftempty && rightempty ){ // Can Plant
                    flowerbed[i] = 1 ; 
                    n -- ; 

                    if( n == 0 ) {
                        return true ; 
                    }
                }
            }
        }

        return false ; 
        
    }
};