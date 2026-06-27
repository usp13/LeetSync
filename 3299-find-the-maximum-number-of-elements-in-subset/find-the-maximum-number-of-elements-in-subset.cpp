class Solution {
public:
    map<long long, int> cnt;
    map<long long, int> dp;

    int solve(long long x) {
        
        
        // DP has value
        if (dp.count(x))
            return dp[x];

        int ans = 1;

        // We can place two x's and continue to x²
        if (cnt[x] >= 2 && x <= LLONG_MAX / x && cnt.count(x * x)) {

            ans = 2 + solve(x * x);
        }

        return dp[x] = ans; // storing value in dp
    }

    int maximumLength(vector<int>& nums) {
        for (int x : nums)
            cnt[x]++;

        int ans = 0;

        // Handle 1 separately
        if (cnt.count(1)) {
            int c = cnt[1];
            ans = max(ans, (c % 2) ? c : c - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;
            ans = max(ans, solve(x));
        }

        return ans;
    }
};