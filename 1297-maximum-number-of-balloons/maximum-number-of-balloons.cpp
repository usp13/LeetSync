class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int n = text.length() ;   

        unordered_map<char,int> mp ; 

        for( int i = 0 ; i < n ; i++ ){
            mp[text[i]]++ ; 
        }

        int possible = min({ mp['b'], mp['a'],
        mp['l'] / 2,  mp['o'] / 2, mp['n'] });

        return possible ;

    }
};