class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size() ; 

        int ans = 0 ; 

        for( int i = 0 ; i < n ; i++ ){

            int e = 0 ; 
            int o = 0 ;

            for( int j = i ; j < n ; j++ ){

                if( nums[j] % 2 == 0 ){
                    e++ ;
                }
                else {
                    o++ ;
                }


                if(  o > 0 && e * b * 1LL <= o * a *1LL ){
                    ans ++; 
                }
            }
        }

        return ans ; 
        
    }
};