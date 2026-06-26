class Solution {
public:
    // Fenwick  /Binary Indexed  Tree (BIT)
    vector<long long> bit;
    int N;

    void update(int idx, long long val) {
        while (idx <= N) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

    long long query(int idx) {
        long long ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Convert the array:
        // target -> +1
        // others -> -1
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int val = (nums[i] == target) ? 1 : -1;
            prefix[i + 1] = prefix[i] + val;
        }

        // Coordinate Compression
        vector<long long> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        unordered_map<long long, int> compress;

        for (int i = 0; i < all.size(); i++) {
            compress[all[i]] = i + 1; // 1-based indexing
        }

        N = all.size();
        bit.assign(N + 1, 0);

        long long ans = 0;

        // Count previous prefix sums smaller than current
        for (long long p : prefix) {
            int idx = compress[p];

            ans += query(idx - 1);
            update(idx, 1);
        }

        return ans;
    }
};