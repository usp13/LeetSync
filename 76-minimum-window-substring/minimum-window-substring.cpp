class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length() ; 
        int m = t.length() ; 
        
        if( m > n  ){
            return "" ; 
        }

        // SLIDING WINDOW 

        unordered_map<char,int> mp ; 

        for( int i = 0 ; i < t.length() ; i++ ){
            mp[t[i]]++ ;
        }

        int reqcount = t.length() ; 

        int i = 0 ; 
        int j = 0 ; 

        int windowsize = INT_MAX ; 
        int start = 0 ; 

        // SLIDING WINDOW 
        while( j < n ){

            char ch = s[j] ; 

            if( mp[ch] > 0 ){
                reqcount -- ; 
            }

            mp[ch] -- ;

            while( reqcount == 0 ){
                
                int currsize = ( j - i + 1) ; //Current substring size

                if( windowsize > currsize ){

                    windowsize = currsize ;

                    start = i ; 

                }

                mp[s[i]]++ ; 

                if( mp[s[i]] > 0 ){
                    reqcount ++ ; 
                }

                i++ ; // LEFT POINTER SLIDES 
            }

            j++ ; // RIGHT POINTER SLIDEs

        }

        string ans = "" ; // Initally answer is empty

        if( windowsize != INT_MAX ){ // if not max
            ans = s.substr( start , windowsize ) ;  // Put substring in the ans 
        }

        return ans ; 

        
    }
};