class Solution {
public:

    // s.substr( startidx , length ) ;

    int dp[301] ; //DP 

    int n ; 
    unordered_set<string> st ; 

    bool solve( int idx , string& s ){

        if( idx >= n ){
            return true ; 
        }

        if( dp[idx] != -1 ){
            return dp[idx] ; 
        }

        if( st.find(s) != st.end()){ // if present in set
            return true ;
        }

        //if not present , break into substr and check

        for( int l = 1 ; l <= n ; l++ ){

            string temp = s.substr( idx , l ) ; // substr of length 'l'

            if( st.find(temp) != st.end() && solve(idx + l , s )){ // if found in set 
                return  dp[idx] = true ; 
            }
        }

        return dp[idx] = false ;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        n = s.length() ;

        memset( dp , -1 , sizeof(dp) ) ; 

        for( string& word : wordDict ){
            st.insert( word ) ; // inserting word in set for fater retrieval
        }

        return solve( 0 , s ) ; 

    }
};