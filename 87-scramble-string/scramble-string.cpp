class Solution {
public:

    unordered_map<string,bool> mp ; 

    bool solve( string s1 , string s2 ){
        
        if( s1 == s2 ) return true ;

        if( s1.length() != s2.length() ){
            return false ;
        }


        string key = s1 + "-" + s2 ;

        if(mp.find(key) != mp.end() ){
            return mp[key] ; 
        }

        bool ans = false ;
        int n = s1.length() ; 

        for( int i = 1 ; i < n ; i++ ){

            // SWAPPED 
            bool swap = solve( s1.substr(0,i) , s2.substr(n-i,i) ) && solve( s1.substr(i,n-i) , s2.substr(0,n-i)) ; 

            if( swap == true ){
                ans = true ;
                break ;  
            }

            // NOT SWAPPED 
            bool notswap = solve( s1.substr(0,i) , s2.substr(0,i) ) && solve( s1.substr(i,n-i) , s2.substr(i,n-i)) ; 

            if( notswap == true ){
                ans = true ;
                break ;  
            }
        }

        return mp[key] = ans ; 
    }
     
    bool isScramble(string s1, string s2) {

        mp.clear() ;
        return solve( s1 , s2 ) ; 
        
    }
};