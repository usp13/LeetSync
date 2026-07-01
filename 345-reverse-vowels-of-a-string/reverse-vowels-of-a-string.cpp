class Solution {
public:

    bool isvowel( char ch ){
        if( ch == 'a' || ch == 'A' ||
        ch == 'e' || ch == 'E' ||
        ch == 'i' || ch == 'I' ||
        ch == 'o' || ch == 'O' ||
        ch == 'u' || ch == 'U' ){
            return true ;
        }
        return false ;
    }
    string reverseVowels(string s) {
        
        int n = s.length() ; 
        int l = 0 ; 
        int r = n-1 ; 

        while( l < r ){

            if( !isvowel(s[l]) ){
                l++ ; // move forward
            }
            else if( !isvowel( s[r]) ){
                r-- ; // move back 
            }
            else {
                swap( s[l] , s[r] ) ; 
                l++ ; 
                r-- ; 
            }
        }

        return s ; 
    }
};