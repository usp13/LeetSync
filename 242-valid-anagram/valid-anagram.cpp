class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.length() ;
        int m = t.length() ;

        if( n != m ) return false ;

        unordered_map<char,int> mp ; 

        for( int i = 0 ; i < n ; i++ ){
            mp[s[i]] ++ ; // adding all the characters of sting s in map
        }

        for( int i = 0 ; i < m ; i++ ){
            mp[t[i]] -- ; // removing all the characters of sting s in map
        }

       for( auto &p : mp ){
            if( p.second != 0 ){
                return false ; 
            }
        }

        return true ; 


        
    }
};