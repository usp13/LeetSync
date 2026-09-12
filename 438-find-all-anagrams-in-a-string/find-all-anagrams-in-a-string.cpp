class Solution {
public:
    bool allzero(vector<int>& counter) {
        for (int &i : counter) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int n = s.size();

        vector<int> counter(26, 0);

        for (int i = 0; i < p.size(); i++) {
            char ch = p[i];
            counter[ch - 'a']++;
        }

        int i = 0;
        int j = 0;
        vector<int> ans;
        int k = p.length();

        while (j < n) {

            // Add current character
            counter[s[j] - 'a']--;

            if (j - i + 1 == k) {

                if (allzero(counter)) {
                    ans.push_back(i);
                }

                // Remove leftmost character
                counter[s[i] - 'a']++;

                i++;
            }

            j++;
        }

        return ans;
    }
};