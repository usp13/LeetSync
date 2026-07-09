class Solution {
public:
    bool isSubsequence(string s, string t) {

        //O(N*M)
        // while(  i < s.length() && j < t.length()){
        //     if( s[i] == t[j]){
        //         i++ ; // s-char move ahead
        //     }

        //     j++ //t-char move ahead
        // }
        //return i == s.length( )

        int m = s.length() ; 
        int n = t.length() ;

        map<char , vector<int> > mp ; 

        for( int i = 0 ; i < n ; i++ ){ // mapping and their indexs
            mp[t[i]].push_back(i) ; 
        } 

        int prev = -1 ; 

        for( int i = 0 ; i < m ; i++ ){

            char ch = s[i] ; 

            if( mp.find(ch) == mp.end() ){// if not found
                return false ; 
            }

            vector<int> indices = mp[ch] ;

            auto  itr = upper_bound( indices.begin() , indices.end() , prev ) ;

            if( itr == indices.end() ){
                return false ; // not found the index
            }

            // update the prev to index of itr
            prev = *itr ; 
        }

        return true ; 

        
    }
};