class Solution {
public:
    
    long long modd = 1e9 + 7 ;
    
    int divisibleGame(vector<int>& nums) {

        int n = nums.size() ; 
        
        unordered_set<int> st  ;
        st.insert(2) ; 

        for( int i = 0 ; i < n ; i++ ){
            for( int d = 2 ; d * d <= nums[i] ; d++ ){

                if( nums[i] % d == 0 ){
                    st.insert(d) ;
                    st.insert( nums[i] / d ) ;
                }
            }

            if( nums[i] > 1 ){
                st.insert(nums[i]) ; 
            }
        }

        long long bdiff = INT_MIN ;
        int bk = 2 ; 

        for( int value : st  ){

            long long curr = INT_MIN ;
            long long maxi = INT_MIN ;

            for( int num : nums ){

                long long val = ( num % value == 0 ) ? num : -num ;

                if( curr == INT_MIN ) {
                    curr = val ;
                }
                else {
                    curr = max( val , curr + val ) ; 
                }

                maxi = max( maxi , curr ) ; 
            }

            if( ( maxi == bdiff && value < bk ) || maxi > bdiff ){
                bdiff = maxi; 
                bk = value ; 
            }
        }

        long long ans = ( bdiff % modd) * (bk % modd) % modd ;

        if( ans < 0 ) ans += modd ; 

        return (int) ans ; 
    }
};