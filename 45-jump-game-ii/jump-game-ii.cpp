class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if( n == 1) return 0;

        int ans = 1 ;

        int maxxx = nums[0];
        int curr = nums[0];
        int i = 1 ;
        
        while( maxxx< n-1){

            if(i + nums[i] > curr){
                curr = i + nums[i];
            }

            if(i == maxxx){
                maxxx = curr ;
                ans ++ ;
            }

            i ++ ;
        }
        
        return ans ;
    }
};