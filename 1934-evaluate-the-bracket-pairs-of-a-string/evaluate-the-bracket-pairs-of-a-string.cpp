class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store knowledge in map
        for (auto &it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans = "";
        int n = s.length();
        int i = 0;

        while (i < n) {

            if (s[i] != '(') {  // its a opening Bracket
                ans.push_back(s[i]);
            }
            
            else {

                i++; // skip '('

                string temp = "";

                while (s[i] != ')') {
                    temp.push_back(s[i]);
                    i++;
                }

                // Add value if key exists, otherwise '?'
                if (mp.count(temp)) {
                    ans += mp[temp];
                }
                else {
                    ans += "?";
                }
            }

            i++;
        }

        return ans;
    }
};