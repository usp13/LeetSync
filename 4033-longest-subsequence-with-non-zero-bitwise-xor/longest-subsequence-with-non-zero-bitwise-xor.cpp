class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        vector<int> nums1 = nums;
        
        int n = nums.size() ;
        
        int m = nums1.size() ;
        
        int total = 0 ;

        for( int i = 0 ; i < n ; i++){
            total = total ^ nums1[i] ;
        }

        if( total != 0 ){
            return m ;
        }
        else {
            for( int i = 0 ; i < m ; i++){
                if( nums1[i] != 0){
                    return m - 1 ;
                }
            }

            return 0 ;
        }
        

        
    }
};