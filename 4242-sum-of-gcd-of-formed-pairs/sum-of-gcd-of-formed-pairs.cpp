class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size() ; 
        vector<int> arr(n) ;
        
        int curr = 0 ; //current max
        int maxi = 0 ; // max

        for( int i = 0 ; i < n ; i++){
            curr = max(curr, nums[i]) ;
            arr[i] = gcd(nums[i], curr) ;
        }

        vector<int> brr = nums ;

        sort(arr.begin() , arr.end()) ; // sort

        long long ans = 0 ; 

        // TWO POINTERS
        long long l = 0 ; //left
        long long r = n-1 ; //right

        while( l < r ){
            
            ans += (gcd(arr[l], arr[r])) ;
            
            l++ ;

            r--;
            
        }

        return ans ; 
        
    }
};