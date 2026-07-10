class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans (n+1)  ;

        if( n == 0 ){
            return ans ; 
        }

        ans[0] = 0 ; 

        for( int i = 0 ; i <= n ; i++ ){

            if( i % 2 != 0 ){ // odd number will have 1 a 0th bit in binary 
                ans[i] = ans[i/2] + 1 ; 
            }
            else {
                ans[i] = ans[i/2] ; 
            }
        }

        return ans ; 
        
    }
};