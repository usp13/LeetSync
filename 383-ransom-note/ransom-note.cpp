class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int m = ransomNote.size();
        int n = magazine.size();

        vector<int> freq(26, 0);

        // Count characters available in magazine
        for (int i = 0; i < n; i++) {
            freq[magazine[i] - 'a']++;
        }

        // Use characters to construct ransomNote
        for (int i = 0; i < m; i++) {

            int index = ransomNote[i] - 'a';

            // Character not available
            if (freq[index] == 0) {
                return false;
            }

            // Consume the character
            freq[index]--;
        }

        return true;
    }
};