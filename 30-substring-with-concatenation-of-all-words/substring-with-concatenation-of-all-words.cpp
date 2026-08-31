class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> mp;

        // Frequency of each word
        for (string word : words) {
            mp[word]++;
        }

        // Try each possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> seen;

            int left = offset;
            int count = 0;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not present in words
                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                // Too many occurrences of this word
                while (seen[word] > mp[word]) {

                    string leftWord = s.substr(left, wordLen);

                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found a valid concatenation
                if (count == wordCount) {
                    result.push_back(left);

                    // Move window forward
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return result;
    }
};