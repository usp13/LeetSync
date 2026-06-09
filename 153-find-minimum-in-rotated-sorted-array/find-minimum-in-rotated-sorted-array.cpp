class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size() ; 
        
        // USING binary search and two pointers 
        int l = 0 ; 
        int r = n-1 ;

        while( l < r ){

            int mid = l + (r-l) / 2 ; // Binary Search Using MID

            if( nums[mid] > nums[r] ){
                l = mid + 1 ; // move left pointer to mid + 1 
            }
            else {
                r = mid ; 
            }
        }

        return nums[r] ;
        
    }
};