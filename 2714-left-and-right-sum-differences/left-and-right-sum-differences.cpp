class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();  

        // SPACE COMPLEXITY - O(2N)
        // vector<int> rightsum ;
        // vector<int> leftsum ;
        
        // Constant Space Complexity O(1)

        int currsum = 0 ; // Current sum till index i
        int totalsum = 0 ;  // total sum of the array

        for( int i = 0 ; i < n ; i++  ){
            totalsum += nums[i] ; 
        }

        vector<int> ans(n) ; 

        for( int i = 0 ; i < n ; i++ ){

            int leftsum = currsum ; // currsum till now acts as Left sum

            currsum += nums[i] ; 

            int rightsum = totalsum - currsum ; 

            ans[i] = abs( rightsum - leftsum ) ; 

        }

        return ans; 
    }  
};