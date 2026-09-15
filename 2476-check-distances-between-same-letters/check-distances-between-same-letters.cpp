class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        int n = s.length() ; 

        vector<int> mp( 26 , -1) ; // Map : stores the first occurance 

        for( int i = 0 ; i < n ; i++){

            int c = s[i] - 'a' ; // character

            if( mp[c] == -1 ){
                mp[c] = i ;
            }

            else {
                int d = i - mp[c] - 1 ; // actual distance

                if( d != distance[c] ){ // if the distance is not present 
                    return false ; 
                }
            }
        }

        return true ;
    }
};