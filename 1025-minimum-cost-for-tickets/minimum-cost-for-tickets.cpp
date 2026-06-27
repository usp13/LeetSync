class Solution {
public:

    int dp[366] ; // Maz days in a Year 

    int solve( vector<int>& days, vector<int>& costs , int n , int i  ){

        // Base case 
        if( i >= n ) return 0 ; // Cant travel , so no cost 

        if( dp[i] != -1 ){
            return dp[i] ; 
        }

        // 1 Day Pass
        int cost1 = costs[0] + solve( days , costs , n , i+1) ;

        // 7 Day pass 
        int j = i ;
        int maxdays = days[i] + 7 ;

        while( j < n && days[j] < maxdays ){
            j++ ; 
        }  

        int cost7 = costs[1] + solve( days , costs , n , j ) ;

        // 30 Day pass 
        j = i ;
        maxdays = days[i] + 30 ;

        while( j < n && days[j] < maxdays ){
            j++ ; 
        }  

        int cost30 = costs[2] + solve( days , costs , n , j ) ;


        

        return dp[i] = min( {cost1 , cost7 , cost30 } ) ;  // Solving and storing in DP 


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size() ; 

        memset( dp , -1 , sizeof(dp) ) ; 

        return solve( days , costs , n , 0 ) ;
        
    }
};