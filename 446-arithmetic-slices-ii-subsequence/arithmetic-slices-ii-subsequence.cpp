class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {


        // Mapping (MAP) : Common diff -> Count of subsequesnce

        int n = nums.size() ; 

        int ans = 0 ; 

        unordered_map<long long ,int> mp[n] ; // Array of Map

        for( int i = 0 ; i < n ; i++ ){ // forward pointer 
            for( int j = 0 ; j < i ; j++ ){ // backward pointer

                long long  diff = (long long )nums[i] - nums[j] ; 

                auto itr = mp[j].find(  diff ) ; 

                int countatj = ( itr == end(mp[j] ) ? 0 : itr ->second ) ; // Count at J for a difference = diff

                mp[i][diff] += countatj  +  1 ;

                ans += countatj ;         

            }
        }

        return ans ; 
        
    }
};