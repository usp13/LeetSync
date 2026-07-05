class Solution {
public:
    bool canMakeSubsequence(string s, string t) {

        int n = s.length() ; 
        int z = 0 ; 
        int o = 0 ; 

        for( char ch: t ){

            int oldz = z ; 
            int oldo = o ; 

            if( oldz < n && s[oldz] == ch ){
                z = oldz + 1 ; 
            }

            int g = oldo ; 
            
            if( oldo < n && s[oldo] == ch ){
                g = max( g , oldo + 1 ) ; 
            }

            if( oldz < n ){
                g = max( g , oldz + 1 ) ; 
            }

            o = g ;

            if( o == n ) return true ; 
        }

        bool ans = ( o == n ) ; 

        return ans ; 
    }
};