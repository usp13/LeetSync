class Solution {
public:
    typedef long long ll;

    ll dp[1001][1001];

    // DP : RECURSION + MEMOISATION
    ll solve(string& s, string& t, int m, int n) {

        // Empty t can be formed in exactly 1 way
        if (n == 0) {
            return dp[m][n] = 1;
        }

        // Non-empty t cannot be formed from empty s
        if (m == 0) {
            return dp[m][n] = 0;
        }

        // Already calculated
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s[m - 1] == t[n - 1]) {
            return dp[m][n] =
                solve(s, t, m - 1, n - 1) +
                solve(s, t, m - 1, n);
        }
        else {
            return dp[m][n] =
                solve(s, t, m - 1, n);
        }
    }

    int numDistinct(string s, string t) {

        int m = s.length();
        int n = t.length();

        memset(dp, -1, sizeof(dp));

        return solve(s, t, m, n);
    }
};