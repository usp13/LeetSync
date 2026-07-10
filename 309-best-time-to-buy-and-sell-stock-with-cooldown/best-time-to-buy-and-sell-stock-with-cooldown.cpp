class Solution {
public:

    // BUY function : solve( prices , day + 1 or 2  , n , true ) ;

    // SELL function : solve( prices , day + 1 or 2  , n , false  ) ;

    int n ; 
    int dp[5001][2] ; 

    int solve( vector<int>& prices , int day , int n ,bool buy ){

        if( day >= n ){
            return 0 ; 
        }

        if( dp[day][buy] != -1 ){
            return dp[day][buy] ; 
        }


        int profit = 0 ; 

        if( buy ){
            int take = solve( prices , day+1 , n , false ) - prices[day] ; // Buying the stock , so money deducted from profit , also we cannot sell the next day (COOLDOWN)

            int nottake = solve( prices , day+1 , n , true ) ; // Not baught , can buy the next day 


            profit = max( {profit , take , nottake} )  ;
        }
        else {

            int sell = prices[day] + solve( prices , day+2 , n , true ) ; // if sold today , today's profit is added + next day you cannot buy, so for the day + 2 you can buy (COOLDOWN)

            int notsell = solve( prices , day + 1 , n , false ) ; // if not selling today , we will be selling the next day/tommorrow

            profit = max( { profit , sell , notsell }) ; 

        }

        return dp[day][buy] = profit ; 

       
    }
    int maxProfit(vector<int>& prices) {

        n = prices.size() ; 

        memset( dp , -1 , sizeof(dp) ) ; 

        bool buy = true ; // first day compulsory buy

        return solve( prices , 0 , n , buy ) ; 
        
    }
};