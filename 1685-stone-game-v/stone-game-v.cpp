class Solution {
public:

    // DP : Recursion + Memoization
    int dp[501][501];

    int solve(int l, int r, vector<int>& prefix) {

        // Only one stone
        if (l >= r)
            return 0;

        // Already calculated
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Try every possible split
        for (int mid = l; mid < r; mid++) {

            // Sum of l ... mid
            int lsum = prefix[mid + 1] - prefix[l];

            // Sum of mid + 1 ... r
            int rsum = prefix[r + 1] - prefix[mid + 1];

            if (lsum < rsum) {

                // Left side is smaller
                ans = max(ans, lsum + solve(l, mid, prefix));

            }
            else if (lsum > rsum) {

                // Right side is smaller
                ans = max(ans, rsum + solve(mid + 1, r, prefix));

            }
            else {

                // Both sides are equal
                ans = max({
                    ans,
                    lsum + solve(l, mid, prefix),
                    rsum + solve(mid + 1, r, prefix)
                });
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, prefix);
    }
};