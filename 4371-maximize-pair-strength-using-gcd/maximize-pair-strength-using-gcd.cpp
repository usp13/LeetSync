class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        int n = nums.size() ; 

        long long ans = 0 ; 

        for( int i = 0 ; i < n ; i++ ){

            for( int j = i+1  ; j < n ; j++ ){

                long long g = gcd( nums[i] , nums[j]) ; 

                long long s = 1LL * (nums[i]/g) * ( nums[j] / g) ;  // strength

                ans = max( ans , s ) ; 
                
            }
        }

        return ans ; 

    }
};