class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size() ; 

        k = k%n ; // Keeps the rotation in bound 

        // TWO pointers with a Temporary array 

        vector<int> ans(n) ;

        for( int i = 0 ; i < n ; i++ ){

            int newidx = ( i + k )%n ; // new shifted index after k Rotation

            ans[newidx] = nums[i] ; // Placing that nums[i] in ans[newidx] after rotation

        }

        for( int i = 0 ; i < n ; i++ ){

            nums[i] = ans[i] ; // Copied back the Rotated array in nums array 

        }

        
        
    }
};