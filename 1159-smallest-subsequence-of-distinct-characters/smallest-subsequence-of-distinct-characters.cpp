class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> last(26);
        vector<bool> visited(26);

        string ans = "";

        int n = s.length();

        for( int i = 0 ; i < n ; i++){
            last[s[i] - 'a'] = i;
        }

        for( int i = 0 ;  i< n ; i++){
            if( visited[s[i] - 'a'])
            continue;


            while(!ans.empty() && ans.back() > s[i] && last[ans.back() -'a']> i){
                visited[ans.back() - 'a'] = false ;
                ans.pop_back();
            }

            ans.push_back(s[i]) ;
            visited[s[i] - 'a'] = true ;
        }

        return ans ;
        
    }
};


