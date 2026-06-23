class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n1 = word1.length() ;
        int n2 = word2.length() ;

        string ans = "" ;

        int i = 0 ; 
        int j = 0 ; 

        while( i < n1 || j < n2 ){

            if( i < n1 ){ // pushing word 1 
                //ans += word1[i] ;
                ans.push_back(word1[i]) ;

            }

            if( j < n2 ){ // word 2
                //ans += word2[i] ;
                ans.push_back(word2[j]) ;
            }

            i++ ;
            j++ ;
        }


        return ans ;
    }
};