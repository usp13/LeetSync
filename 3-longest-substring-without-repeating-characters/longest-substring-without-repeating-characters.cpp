class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int maxlen = 0 ;
        int l = 0 ;
        int r = 0 ;

        vector<int> hash( 128, -1) ;


        while(r < n ){
            if( hash[s[r]] != -1){
                if(hash[s[r]] >= l){

                    l = hash[s[r]] + 1 ;
                }
            }

            hash[s[r]] = r ;

            int len = r-l+1 ;

            maxlen = max(len, maxlen) ;

            r++ ;
        }
        
        return maxlen ;
    }

};