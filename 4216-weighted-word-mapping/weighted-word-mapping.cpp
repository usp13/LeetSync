class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans = "";

        for (string &s : words) {
            int sum = 0;

            for (char c : s) {
                int idx = c - 'a';
                sum += weights[idx];
            }

            int rem = sum % 26; // Modulo 26

            ans.push_back('z' - rem); // Reverse Alphabetical order
        }

        return ans;
        
    }
};