class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        int n = s.length() ;

        unordered_map<string,string> mp ; 

        for( auto &i : knowledge ){
            mp[i[0]] = i[1] ; 
        }

        string ans = ""  ;
        int i = 0 ;

        while( i < n ){

            if( s[i] == '('){
                int j = s.find( ")" , i + 1 ) ; // gets the first occurance of closing bracket  

                string temp = s.substr( i + 1 , j - i - 1 ) ; 

                ans += mp.count(temp) ? mp[temp] : "?" ; 

                i = j ; 
            }
            else { // Alphabet 
                ans.push_back( s[i] ) ; 
            }

            i++ ; 
        } 

        return ans ; 

    }
};