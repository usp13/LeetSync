class Solution {
public:

    int dp[100001];

    // DP : Recursion + Memoization
    int solve(int num) {

        if (num == 0) {
            return 0;
        }

        if (dp[num] != -1) {
            return dp[num];
        }

        // Remove the least significant set bit and count it.
        return dp[num] = 1 + solve(num & (num - 1));
    }

    vector<int> countBits(int n) {

        memset(dp, -1, sizeof(dp));

        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            ans.push_back(solve(i));
        }

        return ans;
    }
};