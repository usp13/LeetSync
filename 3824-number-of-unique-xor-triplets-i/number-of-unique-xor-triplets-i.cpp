class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        

        // X XOR X = 0 
        // 0 XOR x = x 

        int n = nums.size() ; 

        if( n <= 2 ){
            return n ; 
        }

        int ans = 1 ; 
        while( ans <= n ){
            ans <<= 1 ; 
        }

        return ans ; 
        
    }
};