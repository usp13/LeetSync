class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int n = text.length() ;   

        unordered_map<char,int> mp(26) ; 

       for(char ch : text) {
            mp[ch]++;
        }

        int possible = min({ mp['b'], mp['a'],
        mp['l'] / 2,  mp['o'] / 2, mp['n'] });

        return possible ;

    }
};