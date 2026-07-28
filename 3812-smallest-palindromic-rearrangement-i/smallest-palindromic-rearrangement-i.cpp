class Solution {
public:
    string smallestPalindrome(string s) {
        
        // Palindrome is exactly the mirror from the center 
        // Sort the half and paste the revese of that half on the backside

        int n = s.length() ; 

        int mid = n / 2 ; 

        sort( s.begin() , s.begin() + mid ) ;  // sorted the half

        for( int i = 0 ; i < mid ; i++ ){

            s[ n-1-i ] = s[i] ; // pushing the last half same as the firsthalf

        }

        return s ; 

    }
};