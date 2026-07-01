class Solution {
public:
    string reverseWords(string s) {

        int n = s.length() ;  

        //TWO POINTERS
        int l = 0 ; // left pointer for beginning of word
        int r = 0 ; // right keeps track of SPACES b/w words
        int i = 0 ; // Temp pointer

        reverse(s.begin() , s.end()) ; // first reverse the whole string

        while( i < n ){

            while( i < n && s[i]  != ' '){ // when i gets a character , it gives to r 
            s[r] = s[i] ; // assign char to r's char
            
            r++ ; 
            i++ ;

            }

            if( l < r ){

                reverse( s.begin() + l , s.begin() + r ) ; // reverse the charactes of the revesed word to get the correct word

                s[r] = ' ' ; // assign one space 
                r++ ; // move r ahead

                l = r ; // equal the pointers


            }

            i++ ; // move the pointer ahead 

        }

        s = s.substr(0,r-1) ; 

        return s ; 
        
    }
};