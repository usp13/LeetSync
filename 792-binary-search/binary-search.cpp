class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // BINARY SEARCH 
        int l = 0; 
        int r = n-1;

        while( l<= r){

            int mid = l + ( r - l )/2 ;

            if(nums[mid]==target){
                return mid ;
            }

            else if (nums[mid]< target) {
                l = mid + 1 ; //right side search
                continue ;
            }

            else if (nums[mid] > target)  {
                r = mid - 1 ; //left side search
                continue ;
            }
            
        }
        
        return -1 ;

    }
};