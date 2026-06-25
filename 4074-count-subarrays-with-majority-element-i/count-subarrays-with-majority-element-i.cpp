class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> arr(n+1);

        vector<int> nums1 = nums ;

        for( int i = 0 ; i < n ; i++){
            arr[i+1] = arr[i] + (nums1[i] == target ? 1 : -1) ;
        }

        int ans = 0 ;

        for( int i = 1 ; i <= n ; i++){
            for( int l = 0 ; l < i ; l++){
                if(arr[i] - arr[l] > 0){
                    ans ++ ;
                }
            }
        }

        return ans ;

    }
};