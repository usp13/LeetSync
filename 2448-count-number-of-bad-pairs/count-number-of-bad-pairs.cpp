class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        // Consequtive numbers are counted as GOOD pair 

        // nums[j] - j != nums[i] - i will result into a BAD pair 

        int n = nums.size() ; 

        // MAP
        unordered_map<int,int> mp ; 

        long long ans = 0 ;

        for( int i = 0 ; i < n ; i++ ){

            int diff = nums[i] - i ; 

            int goodpairs = mp[diff] ; 

            int totalpairs = i ;

            ans += ( totalpairs - goodpairs ) ;  // Count of BAS pairs 

            mp[diff] ++ ;  

        }

        return ans;

        
    }
};