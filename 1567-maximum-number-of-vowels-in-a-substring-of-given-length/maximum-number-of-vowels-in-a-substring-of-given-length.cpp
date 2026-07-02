class Solution {
public:

    bool isvowel( char& ch ){

        if( ch == 'a' || ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'){
            return true ; 
        }

        return false ; 

    }

    int maxVowels(string s, int k) {

        int n = s.length() ; 

        int count = 0 ; // Count of Vowels
        int maxv = 0 ; // maxvovwels

        // SLIDING WINDOW PROBLEM
        // TWO pointer stating from same position , one moving ahead for expanding the wondow
        int i = 0 ; 
        int j = 0 ; 

        while( j < n ){

            if( isvowel(s[j])){
                count ++ ; 
            }

            if( j - i + 1 == k ){ // if length == k , the slide the i pointer ahead , keeping track of the i'th char  

                maxv = max( maxv , count ) ;

                if( isvowel( s[i] ) ){ // is the i'th char was a vowel that is missed in expanding the subarray , the count should be decreased by 1 
                    count -- ;
                }

                i++ ;


            }

            j++ ;

        }

        return maxv ; 
        
    }
};