class Solution {
public:
    int maxLength(vector<int>& nums) {

        int n = nums.size() ;
        int best = 2 ; 
        int left = 0 ; 
        int product = 1 ;

        for (int right = 0; right < n ; ++right) {
           
            int x = nums[right];
            
            while (gcd(product, x) > 1){
                product /= nums[left++];
            }

            product *= x;

            best = max(best, right - left + 1);

        }

        return best;
    }
};