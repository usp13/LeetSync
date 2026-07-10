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

            int take = solve(prices, day + 1, n, false) - prices[day];

            int nottake = solve(prices, day + 1, n, true);

            profit = max(take, nottake);

        }
        else {

            int sell = prices[day] + solve(prices, day + 1, n, true) - FEE;

            int notsell = solve(prices, day + 1, n, false);

            profit = max(sell, notsell);
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        n = prices.size();

        FEE = fee;

        dp.assign(n, vector<int>(2, -1));

        bool buy = true;

        return solve(prices, 0, n, buy);
    }
};