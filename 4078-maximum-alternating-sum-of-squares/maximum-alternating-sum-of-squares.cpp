class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size() ; 
        vector<int> arr;
        arr.reserve(n);

        for( auto i : nums){
            arr.push_back(i*i) ;
        }

        sort(arr.begin(), arr.end(), greater<int>()) ;

        int k = (n+1) / 2 ;

        long long p = 0 ; 
        long long z = 0 ;

        for( int i = 0 ; i < n ; i++){
            if( i < k ) {
                p += arr[i];
            }
            else {
                z += arr[i];
            }
        }

        return ( p - z );
    }
};