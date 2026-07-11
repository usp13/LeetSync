class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size() ; 

        vector<pair<int , int>> arr(n) ;

        for( int i = 0 ; i < n ; i++ ){

            arr[i] = { nums1[i] , nums2[i] } ;

        }

        auto lambda = [&]( auto &P1 , auto&P2 ){
            return P1.second > P2.second ; 
        } ;
        
        sort( arr.begin() , arr.end() , lambda ) ;

        priority_queue<int , vector<int> , greater<int>> pq ; // MIN HEAP 

        long long sum = 0 ; // Ksum

        for( int i = 0 ; i <= k - 1 ; i++ ){

            sum += arr[i].first ;
            pq.push( arr[i].first ) ; 

        }

        long long ans  = sum * arr[k-1].second ; 

        for( int i = k ; i < n ; i++ ){

            sum += arr[i].first - pq.top() ; 
            pq.pop() ; 

            pq.push( arr[i].first ) ; 

            ans = max( ans , sum*arr[i].second  ) ; 
        }


        return ans ; 


    }
};