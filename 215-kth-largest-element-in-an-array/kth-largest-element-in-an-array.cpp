class Solution {
public:

    int algorithm( vector<int>&nums , int l , int r ){

        int p = nums[l] ; //pivot 
        int i = l+1 ; 
        int j = r ;

        while( i <= j ){

            if( nums[i] > p && nums[j] < p ){ // not correct place

                swap( nums[i] , nums[j] ) ; 
                i++ ; 
                j-- ;

            }
            if( nums[i] <= p ){ // correct place
                i++ ; 
            }
            if( nums[j] >= p ){ // correct place
                j-- ; 
            }
        }

        swap( nums[l] , nums[j] ) ; // swap the pivot index and leftmost index

        return j ; // Pivotindex will be at j 
    }
    int findKthLargest(vector<int>& nums, int k) {

        //The Quickselect algorithm is an efficient method to find the k-th smallest element in an unsorted list. It is closely related to Quicksort, but instead of sorting the entire array, it focuses only on the part containing the desired element, achieving an average time complexity of O(n) and a worst-case of O(n²).

        int n = nums.size() ; 

        // TWO Pointer for Quick Select algo

        int l = 0 ; 
        int r = n - 1 ; 

        // K'th largest elemet would be at nums[k-1]  when in descending order.

        int pivot = 0 ; // Randomly selecting an Pivot index 

        int target = n - k;

        while( true ){

            pivot = algorithm( nums , l , r );

            if( pivot == target ){
                break;
            }
            else if( pivot > target ){
                r = pivot - 1;
            }
            else{
                l = pivot + 1;
            }
        }

        return nums[pivot] ; 
        
    }
};