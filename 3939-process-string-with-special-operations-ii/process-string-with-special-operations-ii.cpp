class Solution {
public:
    char processStr(string s, long long k) {
        
        int n = s.length() ; 
        // For all the special characters, backtrack it to get the k'th character , without building actual ans string

        long long l = 0 ; 

        for( char &ch : s  ){

            if( ch == '*'){ //'*' removes the last character from result, if it exists.
                if( l > 0 ){
                    l-- ;
                }
            }

            else if( ch == '#'){ // '#' duplicates

                l = l*2 ; 

            }

            else if( ch == '%' ){
                // '%' reverses
                continue ;
            }
            else { // Any alphabet 'a' to 'z'
                l++ ; 
            }
        
        }

        if( k >= l ){ // k goes out of bound
            return '.' ; 
        }

        // Back tracking , without building actual string 

        for( int i = n-1 ; i >= 0 ; i-- ){
           
            if( s[i] =='*' ){
                l++ ; 
                // No change in K
            }
            else if( s[i] == '%'){
                k = (l-k-1) ; 
                // No change in l

            }
            else if( s[i] == '#'){
                l = l/2 ;
                k = ( k >= l) ? k-l : k ;
            }
            else {
                l-- ;
            }

            if( k == l ){
                return s[i] ; 
            }
        }

        return '.' ; 
        
    
    }
};