class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp;

        // Count characters in magazine
        for (char ch : magazine) {
            mp[ch]++;
        }

        // Check if ransomNote can be constructed
        for (char ch : ransomNote) {

            if (mp[ch] == 0) { // if not present
                return false;
            }

            mp[ch]--; // decrement the count onec found the character
        }

        return true;
    }
};