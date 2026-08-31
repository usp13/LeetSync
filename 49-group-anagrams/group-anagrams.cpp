class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Categorise by Sorting
        // ANAGRAMS when sorted gives same result

        // Categorise by Frequency Count
        // ANAGRAMS have the same frequency of characters

        vector<vector<string>> ans;

        int n = strs.size();

        if (n == 0) {
            return ans;
        }

        // Key -> Group of anagrams
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {

            // Frequency of 26 lowercase English letters
            vector<int> freq(26, 0);

            for (char ch : str) {
                freq[ch - 'a']++;
            }

            // Convert frequency array into a string key
            string key;

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]);
                key += '#';
            }

            mp[key].push_back(str);
        }

        // Move all groups into answer
        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};