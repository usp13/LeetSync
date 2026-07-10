class Solution {
public:

    // BUY function : solve(prices, day + 1, n, true);

    // SELL function : solve(prices, day + 1, n, false);

    // Transaction Fee applies on a transaction

    int n;
    int FEE;
    vector<vector<int>> dp;

    // DP : Recursion + Memoization
    int solve(vector<int>& prices, int day, int n, bool buy) {

        if (day >= n) {
            return 0;
        }

        if (dp[day][buy] != -1) {
            return dp[day][buy];
        }

        int profit = 0;

        if (buy) {

            // Buying the stock, so money is deducted from profit.
            // After buying today, we move to the next day with the ability to SELL.
            int take = solve(prices, day + 1, n, false) - prices[day];

            // Skip buying today, remain in BUY state for the next day.
            int nottake = solve(prices, day + 1, n, true);

            profit = max(take, nottake);
        }
        else {

            // Selling the stock today:
            // Today's price is added to the profit and the transaction fee is deducted.
            // After selling, we move to the next day with the ability to BUY again.
            int sell = prices[day] + solve(prices, day + 1, n, true) - FEE;

            // Skip selling today, remain in SELL state for the next day.
            int notsell = solve(prices, day + 1, n, false);

            profit = max(sell, notsell);
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        n = prices.size();

        FEE = fee; // Store transaction fee globally

        dp.assign(n, vector<int>(2, -1));

        bool buy = true; // Initially, we are allowed to buy.

        return solve(prices, 0, n, buy);
    }
};