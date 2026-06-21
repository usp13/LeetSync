class Solution {
public:

    void countSort(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi + 1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        int idx = 0;

        for (int i = 0; i <= maxi ; i ++) {
            while (freq[i] > 0) {
                nums[idx++] = i ;
                freq[i]--;
            }
        }
    }

    int maxIceCream(vector<int>& costs, int coins) {

        countSort(costs);

        int ans = 0;

        for (int cost : costs) {
            if (cost > coins) break;

            coins -= cost;
            ans++;
        }

        return ans;
    }
};