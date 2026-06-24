class Solution {
public:

    int n ;
    // DP : For Memoisation
    int dp[50001] ; 

    int getnextindex(  vector<vector<int>>& arr , int l , int end ){

        
        int r = n - 1 ;

        int ans = n + 1 ;

        // Binary Search 
        while( l <= r ){

            int mid = l + ( r-l ) / 2 ;

            if( arr[mid][0] >= end ){ // if the index is eq or more than the current jobs's end , we can take that job
                ans = mid ;
                r = mid - 1;
            } 
            else {
                l = mid + 1 ;
            }
        }

        return ans ; // return the nex possible index for taking the job

    }
    

    int solve(  vector<vector<int>>& arr , int i ){
    

        // BASECASE 
        if( i >= n ){
            return 0 ; 
        }

        if( dp[i] != -1 ){
            return dp[i]  ;
        }

        // Next 
        int next = getnextindex( arr , i+1 , arr[i][1] ) ; 

        int take = arr[i][2] + solve( arr , next ) ; // Profit + Next job 
        int nottake =  solve( arr , i+1 ) ; // Not take


        return dp[i] = max( take , nottake ) ;

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        n = startTime.size() ; 

        vector<vector<int>> arr( n , vector<int>(3,0)) ; // (start,end , profit)

        memset( dp , -1 , sizeof(dp)  ) ; 

        for( int i = 0 ; i < n ; i++ ){

            arr[i][0] = startTime[i] ;
         
            arr[i][1] = endTime[i] ;

            arr[i][2] = profit[i] ;

        }

        // auto sorter = [&]( auto& arr1 , auto& arr2 ){
        //     return arr1[0] <= arr2[0] ;
        // } ;

        sort( arr.begin() , arr.end() ) ;

        return solve( arr , 0 ) ; 


        
    }
};