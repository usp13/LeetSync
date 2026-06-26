const int MAXN = 400005;
long long dp[400005];
long long n;

void update(long long i, long long x) {
    for (; i <= n; i += (i & -i))
        dp[i] += x;
}

long long sum(long long i) {
    long long ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += dp[i];
    return ans;
}

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        // int N = nums.size();

        vector<int> v(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) v[i] = 1;
            else v[i] = -1;
        }

        vector<long long> ps(nums.size());
        ps[0] = v[0];


        for (int i = 1; i < nums.size(); i++) ps[i] = ps[i - 1] + v[i];

        vector<long long> prefix;

        prefix.push_back(0);
        for (auto x : ps) prefix.push_back(x);

        vector<long long> all = prefix;

        sort(all.begin(), all.end());

        all.erase(unique(all.begin(), all.end()), all.end());

        map <long long , long long> get_index;

        for(long long i = 0 ; i < all.size() ; i++ ) {
            get_index[all[i]] = i+1;
        } 

        n = all.size();

        memset(dp, 0, sizeof(dp) );

        long long ans = 0;

        for (auto p : prefix) {

            int idx = get_index[p];
            ans += sum(idx - 1);
            update(idx, 1);

        }

        return ans;
    }
};