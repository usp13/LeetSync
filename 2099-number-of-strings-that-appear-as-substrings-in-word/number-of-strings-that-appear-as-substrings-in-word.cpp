class Solution {
public:
    bool isSubstring(string &word, string &pat) {

        int n = word.size(); // word 
        int m = pat.size(); // pattern

        for (int i = 0; i <= n - m; i++) {

            int j = 0;
            
            while (j < m && word[i + j] == pat[j]){
                j++;
            }

            if (j == m){
                return true;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;

        for (string &s : patterns) {

            if(isSubstring(word, s)){
                count++;
            }
        }

        return count;
    }
};