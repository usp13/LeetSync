class Solution {
public:
   
   
    int n ;
    int dp[30005][2];
    
    //Constraints:
    //  1 <= prices.length <= 3 * 104
    //  0 <= prices[i] <= 104

    int solve(vector<int>& prices, int i, int buy){

        // Base Case 
        if (i == n ) return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        // DO not take the stock
        int notTake = solve(prices, i + 1, buy);

        int take;

        if (buy) {
            // Buy the stock
            take = -prices[i] + solve(prices, i + 1, 0);
        }
        else {
            // Sell the stock
            take = prices[i] + solve(prices, i + 1, 1);
        }

        return dp[i][buy] = max(take, notTake);
    }

    int maxProfit(vector<int>& prices) {

        n = prices.size() ; 

        memset(dp, -1, sizeof(dp));

        return solve(prices, 0, 1);
    }
};