class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        int maxFreq = 0;

        // Count frequencies
        for(char ch : word) {
            freq[ch - 'a']++;
            maxFreq = max(maxFreq, freq[ch - 'a']);
        }

        // Bucket sort frequencies
        vector<int> bucket(maxFreq + 1, 0);

        for(int f : freq) {
            if(f > 0) {
                bucket[f]++;
            }
        }

        int ans = 0;
        int rank = 0; // position among used letters

        // Process frequencies from largest to smallest
        for(int f = maxFreq; f >= 1; f--) {

            while(bucket[f]--) {

                int press = rank / 8 + 1;

                ans += press * f;

                rank++;
            }
        }

        return ans;
    }
};