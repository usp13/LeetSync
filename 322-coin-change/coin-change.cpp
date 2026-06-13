class Solution {
public:
    int n;
    int dp[13][10001];

    int solve(int i, int amount, vector<int>& coins) {

        if (amount == 0) return 0;

        if (i == n) return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int nottake = solve(i + 1, amount, coins);

        int take = 1e9 ;
        
        if (coins[i] <= amount)
            take = 1 + solve(i, amount - coins[i], coins);

        return dp[i][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();
        
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, amount, coins);

        return ans == 1e9 ? -1 : ans;
    }
};