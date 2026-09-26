class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store knowledge in map
        for (auto &it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans = "";
        string temp = "";

        int n = s.length();
        int i = 0;

        bool isopenbracket = false; // keeps track of open bracket

        while (i < n) {

            if (s[i] == '(') {
                isopenbracket = true;
            }

            else if (s[i] == ')') {

                isopenbracket = false;

                ans += mp.count(temp) ? mp[temp] : "?";

                temp = ""; // empty temp
            }

            else if (isopenbracket == true) {
                temp.push_back(s[i]);
            }

            else {
                ans.push_back(s[i]);
            }

            i++; // move to next character
        }

        return ans;
    }
};