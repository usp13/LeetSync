class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // BRUTEFORCE : O(N^2)
        // Optimal : O(nlogn)

        int n = nums.size() ; 

        if( n == 0) return 0 ; 

        sort(nums.begin() , nums.end()) ; 
        int lastsmall = INT_MIN ; 
        int longest = 1 ; 
        int count = 0 ; 

        for( int i = 0 ; i < n ; i++ ){

            if(  lastsmall == nums[i] - 1 ){
                count += 1 ; 
                lastsmall = nums[i] ; 
            }
            else if( lastsmall != nums[i] ){
                count = 1 ; 
                lastsmall = nums[i] ; 
            }

            longest = max( longest , count ) ; 
        }

        return longest ; 
        
    }
};