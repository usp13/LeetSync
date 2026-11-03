class Solution {
public:
    int minMoves(vector<int>& nums) {

        long long  n1 = nums[0] ;

        long long  s = 0 ;

        long long  n = nums.size() ;

        for( int i = 0 ; i < n ; ++i ) {

            long long r = nums[i] ;

            s += (long long)r ;
            
            if( r > n1){
                n1 = r ;
            }
        }

        long long  ans = n1* (long long) n - s ;

        return ans ;
        
    }
};